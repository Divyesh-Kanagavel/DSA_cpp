// quick union algorithm to solve union-find problem

#include <iostream>
#include <memory>

class UnionFind
{
    private:
        std::unique_ptr<int[]> id;
        int num_ids;
    
    int find_root(int i)
    {
        while (i != id[i]) i = id[i];
        return i;
    }
    
    public:
        UnionFind(int n) : id(std::make_unique<int[]>(n)), num_ids (n)
        {
            for(int i=0;i<n;i++)
            {
                id[i] = i;
            }          
        }
        // O(N) in worst case to find root
        bool connected(int p, int q)
        {
            int root_p = find_root(p);
            int root_q = find_root(q);
            return root_p == root_q;
        }
        // O(N^2) -> there are N elements and a loop of N elements per element.
        void union_func(int p, int q)
        {
            int id_p = find_root(p);
            int id_q = find_root(q);
            id[id_p] = id_q;
        }

        // group id of an element
        int count(int p)
        {
            return find_root(p);
        }
};

int main()
{
    UnionFind uf(10);
    uf.union_func(1,2);
    uf.union_func(3,4);
    uf.union_func(5,6);
    uf.union_func(7,8);
    uf.union_func(7,9);
    uf.union_func(1,9);
    uf.union_func(2,8);
    uf.union_func(0,5);
    // test prints
    std::cout << uf.connected(2,7) << std::endl;
    std::cout << uf.connected(3,6) << std::endl;
    std::cout << uf.connected(0,6) << std::endl;
    std::cout << uf.connected(5,9) << std::endl;

    std::cout << uf.connected(7,3) << std::endl;

    std::cout << uf.count(7) << " " << uf.count(9) << std::endl;
    std::cout << uf.count(2) <<  " " << uf.count(4) << std::endl;

    return 0;
}
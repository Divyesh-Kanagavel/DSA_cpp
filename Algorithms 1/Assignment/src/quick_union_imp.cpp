// quick union improvements
// - use a weighted quick union -> assign weights to groups and always attach smaller tree to larger tree to keep the resultant tree balanced
// the worst case becomes better -> O(N) -> O(log2(N)) to find roots.
// path compression : when you find root for a node p, attach its parents to root - this works well in practice without additional side effects
// Resultant complexity : O(N + Mlog*N) : N is number of elements, M is number of find ops
// the precise compleixty is : O((N+M)alpha(N)) -> inverse ackerman function -> grows slower than log*N
// quick union algorithm to solve union-find problem

#include <iostream>
#include <memory>

class UnionFind
{
    private:
        std::unique_ptr<int[]> id;
        std::unique_ptr<int[]> sz;
        int num_ids;
    
    int find_root(int i)
    {
        while (i != id[i])
        {
            id[i] = id[id[i]]; // halving the tree by attaching parent to grandparent, can use two pass as well
            i = id[i];
        }
        return i;
    }
    
    public:
        UnionFind(int n) : id(std::make_unique<int[]>(n)), num_ids (n), sz (std::make_unique<int[]>(n))
        {
            for(int i=0;i<n;i++)
            {
                id[i] = i;
                sz[i] = 1;
            }          
        }
        // O(N) in worst case to find root
        bool connected(int p, int q)
        {
            int root_p = find_root(p);
            int root_q = find_root(q);
            return root_p == root_q;
        }

        void union_func(int p, int q)
        {
            int id_p = find_root(p);
            int id_q = find_root(q);
            if (sz[id_p] < sz[id_q])
            {
                id[id_p] = id_q;
                sz[id_q] += sz[id_p];
            }
            else
            {
                id[id_q] = id_p;
                sz[id_p] += sz[id_q];
            }
        }

        // group id of an element
        int group_id(int p)
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

    std::cout << uf.group_id(7) << " " << uf.group_id(9) << std::endl;
    std::cout << uf.group_id(2) <<  " " << uf.group_id(4) << std::endl;

    for(int i=0;i<10;i++)
    {
        std::cout << uf.group_id(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
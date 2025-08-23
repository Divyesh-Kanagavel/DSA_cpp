// union-find algorithm -> find if two components are connected, and if not connect two components

#include <iostream>
#include <memory>

class UnionFind
{
    private:
        std::unique_ptr<int[]> arr;
        int num_ids;
    
    public:
        UnionFind(int n) : arr(std::make_unique<int[]>(n)), num_ids (n)
        {
            for(int i=0;i<n;i++)
            {
                arr[i] = i;
            }          
        }

        bool connected(int p, int q)
        {
            if (arr[p] == arr[q]) // same id 
                return true;
            return false;
        }
        // O(N^2) -> there are N elements and a loop of N elements per element.
        void union_func(int p, int q)
        {
            int pid = arr[p];
            int qid = arr[q];
            if (connected(p,q))
                return;
            for(int i=0;i<num_ids;i++)
            {
                if (arr[i] == pid)
                    arr[i] = qid;
            }
        }
        // group id of an element
        int count(int p)
        {
            return arr[p];
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
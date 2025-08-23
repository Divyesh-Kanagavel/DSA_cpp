// simulation of percolation in NXN grid and computation of 
// transition threshold p* through simulations for mamy times
// optimization of the simulation using union-find algorithm

#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <stdexcept>
#include <chrono>

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
        // O(N^2) -> there are N elements and a loop of N elements per element.
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

class Percolation
{
    public:
        Percolation(int n) : num(n), uf(n*n+2), virtualTop (n*n), virtualBottom (n*n+1)
        {
            if (n < 0)
            {
                throw std::invalid_argument("n must be > 0");
            }
            grid.resize(n);
            for(int i=0;i<n;i++)
            {
                grid[i].resize(n);
            }
        }

        void open(int row, int col)
        {
            if ((row < 0) || (row > num-1) || (col < 0) || (col > num-1))
                throw std::out_of_range("row and col must be between 1 and n");
            grid[row][col] = true;
            int idx = index(row, col);
            if (row == 0) uf.union_func(idx, virtualTop);
            if (row == num-1) uf.union_func(idx, virtualBottom);

            if (row > 0 && grid[row-1][col]) uf.union_func(idx, index(row-1,col));
            if (row < num-1 && grid[row+1][col]) uf.union_func(idx, index(row+1,col));
            if (col > 0 && grid[row][col-1]) uf.union_func(idx, index(row,col-1));
            if (col < num-1 && grid[row][col+1]) uf.union_func(idx, index(row,col+1));

        }

        bool isOpen(int row, int col)
        {
            if ((row < 0) || (row > num-1) || (col < 0) || (col > num-1))
                throw std::out_of_range("row and col must be between 0 and n-1");
            return grid[row][col];
        }

        int numberOfOpenSites()
        {
            int sum = 0;
            for (int i=0;i<num;i++) {
                for (int j=0;j<num;j++) {
                    sum += grid[i][j];
                }
            }
            return sum;
        }

        bool percolates()
        {
            return uf.group_id(virtualTop) == uf.group_id(virtualBottom);
        }


    private:
        std::vector<std::vector<bool>> grid;
        int num;
        UnionFind uf;
        int virtualTop; // virtual node attached to top row
        int virtualBottom; // virtual node attached to bottom row

int index(int row, int col)
{
    if (row >= 0 && row < num && col >= 0 && col < num)
        return row * num + col;
    throw std::out_of_range("Invalid row/col in index()");
}


};

int main()
{
    std::random_device rd;  // Seed (non-deterministic if available)
    std::mt19937 gen(rd()); // Mersenne Twister engine
    const int n = 10;
    std::uniform_int_distribution<> dist(0, n-1); // Range [0, 4]

    Percolation perc(n);
    // perc.open(0,1);
    // perc.open(1,1);
    // perc.open(1,2);
    // perc.open(2,2);
    // perc.open(3,2);
    // perc.open(3,1);
    // perc.open(4,1);
    // experiment -> to determine the threshold probability
    std::vector<int> sites(n*n);
    std::iota(sites.begin(), sites.end(), 0);
    std::shuffle(sites.begin(), sites.end(), gen);
    int idx = 0;
    int row,col;
    auto start = std::chrono::high_resolution_clock::now();  
    while(!perc.percolates())
    {
        // int row,col;
        // do
        // {
        //     row = dist(gen);
        //     col = dist(gen);/* code */
        // } while (perc.isOpen(row,col));
        // randomization optimization
        row = sites[idx] / n;
        col = sites[idx] % n;
        perc.open(row, col);
        idx++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " microseconds\n";

    std::cout << perc.numberOfOpenSites() << std::endl;
    std::cout << "Ratio = " << static_cast<float>(perc.numberOfOpenSites()) / (n*n) << std::endl;

}
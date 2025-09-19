/* selection sort in C++ for generic datatype
Error handling not taken care of for simplicity */

#include <iostream>
#include <functional>
#include <random>
#include <algorithm> 
#include <chrono>

#define NUM 100000

// Function to generate a random vector of integers
std::vector<int> generateRandomIntVector(int N, int min_val, int max_val) {
    std::vector<int> random_vector(N);

    // Create a random number engine and seed it
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define a uniform integer distribution
    std::uniform_int_distribution<int> distrib(min_val, max_val);

    // Fill the vector with random numbers
    std::generate(random_vector.begin(), random_vector.end(), [&]() {
        return distrib(gen);
    });

    return random_vector;
}

template <typename T>
bool lesser(T a, T b)
{
    return a < b;
}

template <typename T>
void exchange(std::vector<T>& vec, int a, int b)
{
    T temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
}
// pass the datatype of the vector as template and also the comparator function
template <typename T, typename Compare>
void insertion_sort(std::vector<T>& vec, Compare comp)
{
    auto vec_size = vec.size();
    if (vec_size <= 0)
    {
        std::cout << "empty vector!\n";
        return;
    }
    else if (vec_size == 1)
    {
        return;
    }
    else
    {
        int i=1;
        while(i!=vec.size())
        {
            for(int j=i;j>0;j--)
            {
                if (lesser(vec[j], vec[j-1]))
                {
                    exchange(vec, j, j-1);
                }
                else
                {
                    break;
                }
            }
            i++;          
        }
    }
}

int main()
{
    std::vector<int> a = generateRandomIntVector(NUM,0,1000);
    // deduce the type of a and also the comparator function from here.
    auto start = std::chrono::steady_clock::now();
    insertion_sort(a, lesser<int>);
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << duration << std::endl;
}

/*
For a random vector of size : 100000, the runtime for insertions sort is :
36251 milliseconds -> 36.251 seconds
*/

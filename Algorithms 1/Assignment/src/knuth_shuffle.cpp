/*
It is very hard to shuffle randomly
Generating random numbers in software depends on the seed which is not completely random
The seed usually depends on the time till midnight or time from a certain date
the datatype used sometimes could serve as bottleneck etc
keep this things in mind when working with randomization
*/
#include <random>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>



using namespace std;

void knuth_shuffle(vector<int>& a)
{
    std::mt19937 generator(static_cast<unsigned int>(time(NULL)));

    for(int i=0;i<a.size();i++)
    {
        std::uniform_int_distribution<int> distribution(0,i);
        int r = distribution(generator);
        std::swap(a[i], a[r]);  // knuth shuffle algorithm O(N)
    }
}

int main()
{
   vector<int> a = {4,5,1,0,9,3,2};

   knuth_shuffle(a);

   for(auto i : a)
   {
    std::cout << i << " ";
   }
   std::cout << std::endl;

}
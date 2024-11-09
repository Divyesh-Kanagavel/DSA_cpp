/*
problem : 
Given an array A of N integers. Find out the minimum value of the following expression for all valid .
a_i and a_j xor a_i or a_j

the most intuitive solution is to search for all pairwise combinations and find the minimum value of the above expression in O(n^2)

but the optimal solution makes use of property that xor of adjacent or elements nearby is smaller than
those which are far off, because usually most signifact bits of adjacent elements will be same, and hence xor will be small
sometimes there may be cases where adjacent elements xor may be bigger than other neighbors but it will be compensated
when comparing the adjacent of the next two elements. for example, 20 xor 19 is bigger than 20 xor 18, but 19 xor 18 is even smaller
so, no need to compare other elements

(a and b) xor (a or b) = a xor b.
*/
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
#define MAXSIZE 100000
int main() {
    int T;
	long int arr[MAXSIZE];
	cin >> T;
	for (int t=0;t<T;t++)
	{
        int N;
		cin >> N;
		for (int i=0;i < N; i++)
		{
            cin >> arr[i];
		}

		

	    std::sort(arr, arr+N);

        int min_val = (arr[0] ^ arr[1]);

		int val;
		for(int i=1;i<N-1;i++)
		{
			val = (arr[i] ^ arr[i+1]);
			if (val < min_val)
			{
				min_val = val;
			}
		}
		std::cout << min_val << std::endl;


	}
}
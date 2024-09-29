#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  
   int T,N;
   long unsigned int K;
   string s;

   cin >> T;

   for(int t=0;t<T;t++)
   {
	    cin >> N >> K ;
		cin >> s;

		int p = -1;

		int num_shifts = 0;
        string s_max = "";
		for(int i=0;i<N;i++)
		{
			if (s.compare(s_max) > 0)
			{
				s_max = s;
				num_shifts = i;
			}
			else if (s == s_max)
			{
				p = i - num_shifts;
				break;
			}
			s = s.substr(1,N) + s[0];
		}
		if (p==-1)
		    std::cout << num_shifts + (K-1)*N << std::endl;
		else
		    std::cout << num_shifts + (K-1)*p << std::endl;
   }

	return 0;
}
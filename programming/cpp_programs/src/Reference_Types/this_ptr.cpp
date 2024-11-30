#include <cstdio>

struct Year
{
	public:
		Year(){
			year = 0;
		}
		bool set_year(int year)
		{
			printf("year = %d\n", year);
			this->year = year;
		}
	private:
		int year;
};
// in the above structure, year is a member variable and in member function set_year, you have an argument year. to disambiguate, we 
// use the this pointer which refers to the current object which is being executed.
// inside a member function, the argument year takes preference over member variable year.

int main()
{
	Year yr;
	yr.set_year(2024);
	return 0;
}

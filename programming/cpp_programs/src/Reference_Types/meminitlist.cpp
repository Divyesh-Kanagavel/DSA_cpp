#include <cstdio>

struct Avout
{
	Avout(const char* name, long apert_year) : name {name}, apert_year{apert_year}
	{}
	void announce() const // const keyword here implies the members of the class won't be modified by the function. it does not change the //state of the class
	{
		printf("name is %s\n", name);
		printf("apert_year is %ld\n", apert_year);
	}

	const char* name;
	long apert_year;
};

int main()
{
	Avout a ("hi", 2025);
	a.announce();
	return 0;
}

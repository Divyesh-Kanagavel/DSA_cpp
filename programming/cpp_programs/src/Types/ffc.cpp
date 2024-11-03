// fully featured class

#include <cstdio>

struct Taxonomist
{
	Taxonomist() // default constructor
	{
		printf("no argument!\n");
	}
	Taxonomist(char c)
	{
		printf("char arguments : %c\n", c);
	}
	Taxonomist(float f)
	{
		printf("float argument : %f\n",f);
	}
};

int main()
{
	// constructors
	Taxonomist t1; // calls default constructor
        Taxonomist t2 {}; // braced init, calls default constructor
	Taxonomist t3 = {'g'}; // equals + braced char init
	Taxonomist t4 {3.1419f};
	//Taxonomist t5(); // paranthesis constructor, but looks like a function call , compiler might not get this
	// when the code is compiled, we see a warning saying empty parantheses interpreted as function declaration.
	// this problem is widely known as the most vexing parse.
	return 0;
}

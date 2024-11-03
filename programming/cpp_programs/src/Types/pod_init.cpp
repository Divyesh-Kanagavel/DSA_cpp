#include <cstdio>
// POD : Plain old datatype
struct podStruct
{
	int a;
	char b[256];
	float c;
};

int main(void)
{
	// different ways of initializing
	podStruct podInit; // no arguments passed to constructor while initializing : may contain zeros or junk , but allowed
	podStruct podInit1{}; // brace initialization, allowed, all fields set to zeros
	podStruct podInit2 = {}; // equals + brace initialziation, allowed, all field set to zeros
	podStruct podInit3 = {42, "hello"}; // equals+brace initialization, allowed, a and b set to values, c = 0
        podStruct podInit4 {42, "hello", 4.31}; // brace initialization, allowed, all three values set
//	podStruct podInit5 = 0; // not allowed, will not compile
//        podStruct podInit6 {42,4.31}; // will not compile, only the fields from right can be left without values being given
//        podStruct podInit7 (42, "hello",4.31); // not allowed , paranetheses init not allowed.
	return 0;
}


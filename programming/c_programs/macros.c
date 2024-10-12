#include <stdio.h>


#define FOO 2
#define ADD(x,y) x+y // there is a bug in this MACRO : when combined with pre-multiplication, it does not provide desired result
#define ADD_FIX(x,y) (x+y)
#define MUL(x,y) (x*y) // there is another bug here.if y is a compound statement like 3+2, expected behaviour is x * (3+2) and not x * 3 + 2.
		       // hence, x and y need to be paranthesised.
#define MUL_FIX(x,y) ((x)*(y))		       
// multiline MACRO
#define SUM_RANGE(start,end) \
	int sum=0;           \
	for(int x =start; x<end;x++) \
             sum+=x;                \
	printf("%d\n",sum)
// there is a potential bug with SUM_RANGE, it uses a variable called sum, and if main function which uses this MACRO has another variable called
// sum, it will conflict this sum, hence it can be enclosed inside a dummy do while loop or simply a paranthesis to block this out.

#define SUM_RANGE_FIX(start,end){ \
	int sum=0;           \
	for(int x =start; x<end;x++) \
             sum+=x;                \
        printf("%d\n",sum);}	
int main()
{
        int sum = 0;
	printf("%d\n", FOO);
	printf("%d\n", 5 * ADD(2,3)); // expectation : 5 * (2+3) = 25, but result = 13 , because ADD(x,y) substitutes x+y in its place making 
				      // 5 * 2 + 3
	printf("%d\n",5*ADD_FIX(2,3));
	printf("%d\n", MUL(3,4+3));
	printf("%d\n",MUL_FIX(3,4+3));
	//MULTILINE MACRO
	printf("Multiline macro example\n");
	//SUM_RANGE(4,11); --> redefinition error
	SUM_RANGE_FIX(4,11)
	return 0;
}


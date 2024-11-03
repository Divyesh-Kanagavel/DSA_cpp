#include <cstdio>

enum class Operation
{
	Add,
	Subtract,
	Multiply,
	Divide
};

struct calculator
{
	calculator()
	{
		printf("empty constructor called\n");
		operation_ = Operation::Add;
	}
	calculator(Operation operation)
	{
		printf("constructor with operation called!\n");
		operation_ = operation;
	}
	int calculate(int a, int b)
	{
		switch(operation_)
		{
			case Operation::Add:
		        {
				return a+b;
				break;
			}
			case Operation::Subtract:
			{
				return a-b;
				break;
			}
			case Operation::Multiply:
			{
				return a*b;
			        break;
			}
			case Operation::Divide:
			{
				if (b == 0)
				{
					return 0;
				}
				else
				{
					return (a/b);
				}
				break;
			}
			default:
			{
				printf("no operation passed!\n");
				return 0;
				break;
			}
		}

	}
	private:
	    Operation operation_;
};

int main()
{
    // different constructions
    calculator c; // default
    printf("%d\n",c.calculate(3,4));
    calculator c1 {};
    printf("%d\n",c1.calculate(3,4));
    calculator c2 = {};
    printf("%d\n",c2.calculate(3,4));
    calculator c3 = {Operation::Add};
    printf("%d\n",c3.calculate(3,4));
    calculator c4{Operation::Subtract};
    printf("%d\n",c4.calculate(3,4));
    calculator c5 {Operation::Divide};
    printf("%d\n",c5.calculate(3,4));
    return 0;
}

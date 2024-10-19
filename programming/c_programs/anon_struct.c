#include <stdio.h>

struct Vec2
{
	int x;
	int y;
};

int scale_sum(int v, struct Vec2 vec)
{
	return (v * vec.x + v * vec.y);
}

int sum(int xs[], int len)
{
	int s = 0;
	for(int i=0;i<len;i++)
	{
		s += xs[i];
	}
        return s;
}


int main()
{
	printf("%d\n", scale_sum(5,(struct Vec2){3,4}));
	printf("%d\n", sum((int []){1,2,3,4,5,6,7}, 7));
	return 0;
}


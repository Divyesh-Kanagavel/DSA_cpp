#include <cstdio>
void towerHanoi(int num , char src, char dst, char tmp)
{
    if (num < 1) // termination condition
    {
        return;
    }
    towerHanoi(num - 1, src, tmp, dst); // recursive call
    printf("move the disc %d from peg %c to %c\n", num, src, dst);
    towerHanoi(num-1, tmp,dst,src);
}

int main()
{
    int num =4 ;
    printf("The sequence of moves involved in the Tower of Hanoi are :\n"); 
    towerHanoi(num, 'A', 'C', 'B');
return 0; 
}

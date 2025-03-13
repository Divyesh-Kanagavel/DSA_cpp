/* 
LKP '18 Contest 2 P1 - Food Lines
After many years of continuous warfare, the country of Collea was left in shambles. This has caused food shortages and famines all across the country. In an attempt to distribute the little food that was produced and prevent food hoarding, the Collean government limited the amount of food that any one person can buy. Soon, Collean citizens are forced to wait in long lines in order to obtain the food they needed. There are currently 
N such food lines in the city of Lachtin, the ith of which has a_i people in it. M  people are going to enter one of the lines in the next hour, where they each enter the shortest line they see. Since Phreia plans to enter the line, she wants to know the length of the line that each person decides to join.
*/

#include <stdio.h>
#include <stdlib.h>

int shortest_line_index(int lines[], int n)
{
    int shortest = 0;
    for (int i=1;i<n;++i)
    {
        if (lines[i] < lines[shortest])
        {
            shortest = i;
        }
    }
    return shortest;
}

void solve(int lines[], int n, int m)
{
    int shortest;
    for (int i=0;i<m;++i)
    {
        shortest = shortest_line_index(lines, n);
        printf("%d\n", lines[shortest]);
        lines[shortest]++;
    }
}
#define MAX_LINES 100
int main()
{
    int lines[MAX_LINES];
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&lines[i]);
    }
    solve(lines, n, m);
    return 0;
}
/* Write a program to print a histogram of the frequencies of different characters in its input. */
#include <stdio.h>

// for simplicity we focus on only the digits and alphabets - ignoring the special characters, punctuations, etc

#define ALPHABETS 26
#define DIGITS 10

int main()
{
    int i, j, c;

    int histogram[ALPHABETS + DIGITS]; // first 26 for alphabets and next 10 for digits
    for(i=0;i<ALPHABETS+DIGITS;++i)
    {
        histogram[i] = 0;
    }

    while((c = getchar()) != EOF)
    {
        if ((c >= '0') && (c <= '9'))
        {
            ++histogram[ALPHABETS+c-'0'];
        }
        else if ((c >= 'a') && (c <= 'z'))
        {
            ++histogram[c-'a'];
        }
        else if ((c>='A') && (c<='Z'))
        {
            ++histogram[c-'A'];
        }
    }
    // printing histogram - horizontal alignment
    for(i=0;i<ALPHABETS;++i)
    {
        printf("%c: ", 'a'+i);
        for(j=0;j<histogram[i];j++)
        {
            printf("#");
        }
        printf("\n");
    }
    for(i=0;i<DIGITS;++i)
    {
        printf("%d: ", i);
        for(j=0;j<histogram[ALPHABETS+i];j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
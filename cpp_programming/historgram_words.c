/* Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.*/

#include <stdio.h>
#define IN 1 /* inside a word */ 
#define OUT 0 /* outside a word */
#define MAX_WORDS 15 /* maximum length of word */
// the current implementation is buggy. it included puncutation mark as part of word length.
// If it needs to be excluded, an additional condition needs to be added.
// for now, we are going ahead with simple implementation given in the word counter example before.
int main()
{
    int c, nw, nc,state,i,j;
    nw = nc = 0;
    state = OUT;
    int histogram[MAX_WORDS];
    for(i=0;i<MAX_WORDS;++i)
    {
        histogram[i] = 0;
    }

    while ((c = getchar ())!= EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            if (nc > MAX_WORDS) // capping to MAX_WORDS
            {
                nc = MAX_WORDS;
            }
            ++histogram[nc-1];
            nc = 0;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
        if (state == IN)
        {
            ++nc;
        }

    }
    printf("\n the number of words are : %d\n", nw);
    printf("\n");
    // drawing histogram - horizontal bars
    for (i=0;i<MAX_WORDS;++i)
    {
        printf("For word : %d\t", i+1);
        for(j=0;j<histogram[i];j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;

}
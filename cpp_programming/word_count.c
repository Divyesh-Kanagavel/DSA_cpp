/* program to count number of words -> word defined by sequence of chars without space, tab or newline*/

#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
/* count number of lines , words, characters in a sequence of text*/
/*
Somet tests:
Single Word : okay
Empty input : considers empty string as a word
Stress test : Really long word, large number of words - yet to do
Punctuation : simple punctuations are considered words - in real life, are not words.
Newlines : okay
Hyphenated Words: okay
Apostrophes: okay.
*/
int main()
{
    int c, nc, nw, nl, state;
    nc = nw = nl = 0;
    state = OUT;
    while((c=getchar())!=EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }
        if ((c == ' ') || (c == '\n') || (c == '\t'))
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }

    printf("number of characters is %d\n", nc);
    printf("number of words are : %d\n",nw);
    printf("number of lines are : %d\n", nl);
    return 0;
}
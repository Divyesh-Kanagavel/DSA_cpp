/* Petya has noticed that when he types using a keyboard, he often presses extra buttons and adds extra letters to the words. 
Of course, the spell-checking system underlines the words for him and he has to click every word and choose the right variant. 
Petya got fed up with correcting his mistakes himself, that’s why he decided to invent the function that will correct the words itself. 
Petya started from analyzing the case that happens to him most of the time, when all one needs is to delete one letter for the word to match a word from the dictionary. 
Thus, Petya faces one mini-task: he has a printed word and a word from the dictionary, and he should delete one letter from the first word to get the second one.
And now the very non-trivial question that Petya faces is: which letter should he delete?*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* in unique snowflakes and compound words problems, we used hashmap to 
store the words/integers and do a quick search to fidn the elements. 
here the string could be million long and hence it is harder to store the
elements in a hash table. even if we use pointers to the string indices in hash tables,
there is a need to string compare two very big strings which is expensive. 
*/

/* the idea is as follows:
consider two strings - abcdxxxef and abcdxxef
there are some common characters which acts as prefix and common suffix characters
there is a character in between from which there is a divergence.
in this case : prefix string is abcdxx of length 6. 
suffix is xxef of length 4. the character whcih could be removed to get string 2 is x
and it is in position 5,6,7. 
the objective is to find the range of characters between len-suffix and prefix+1. 

*/

int prefix_length(char s1[], char s2[]) 
{
    int i=1;
    while (s1[i] == s2[i])
        i++;

    return i-1;
}

int suffix_length(char s1[], char s2[], int len) 
{
    int i = len;
    while (i >= 2 && s1[i] == s2[i-1])
        i--;

    return len-i;
}
#define SIZE 1000000
int main(void)
{
    static char s1[SIZE + 2], s2[SIZE + 2];
    int len, prefix, suffix, total;
    scanf("%s", &s1[1]);
    scanf("%s", &s2[1]);
    len = strlen(&s1[1]);

    prefix = prefix_length(s1, s2);
    suffix = suffix_length(s1, s2, len);

    total = (prefix + 1) - (len - suffix) + 1;
    if (total < 0)
        total = 0;
    printf("%d\n",total);
    
    for(int i=0;i<total;i++)
    {
        printf("%d", i + len-suffix);
        if (i < total-1)
        printf(" ");
        else
            printf("\n");
    }
    return 0;

}

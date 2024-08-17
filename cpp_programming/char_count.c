/* a program to count number of characters in input*/
#include <stdio.h>
int main()
{
    long nc=0;
   /*  while(getchar()!=EOF)
    {
        ++nc;
    }
    printf("%ld\n", nc); */
    // for loop to do the same
    for (nc=0;getchar()!=EOF;++nc)
    ;
    // no body required for for loop, since the update and increment operations achieve what is required.
    // but cpp syntax requires body to be there, hence the semicolon, a null statement.
    printf("%ld\n", nc);
    return 0;

}
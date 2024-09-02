#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000

void expand(char s[], char d[])
{
    int i,j = 0;
    for(i=0; (i < MAXLEN-1) && (j < MAXLEN-1) && s[i]!='\0';i++)
    {
        if (isalnum(s[i]) && s[i+1] == '-' && isalnum(s[i+2]) && (s[i] < s[i+2]))
        {
            if (s[i-1] == '-')
                j--;
            
            int k;
            for(k=0; k<=(s[i+2]-s[i]);++k)
            {           
                d[j++] = s[i]+k;
            }
            i+=2;
        }
        else
        {
            d[j++] = s[i];
        }
    }
    d[j] = '\0';
}

int main(void)
{
    char src[] = "hi i am going to print -a-z-a-z and 2-9 now!";
    char dest[MAXLEN];
    expand(src,dest);
    printf("%s\n", dest);
    return 0;
}
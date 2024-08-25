#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main()
{
    char s[] = "0xF12A";
    printf("%d\n",htoi(s));
    return 0;
}

int htoi(char s[])
{
    int n = 0,i = 0;

    while(s[i]!='\0')
    {
        if ((s[i] == '0') && ((s[i+1] == 'x') || (s[i+1] == 'X')))
        {
            i = i+2;
            continue;
        }
        int temp = s[i];
        if (isalpha(temp))
        {
            temp = tolower(temp);
        }

        if (temp >= '0' && temp <= '9')
        {
            n = 16 * n + (s[i] - '0');
            ++i;
        }
        else if (temp >= 'a' && temp <= 'f')
        {

            n = 16 * n + (temp - 'a' + 10);
            ++i;
        }
    }
    return n;
}
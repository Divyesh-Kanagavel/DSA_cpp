#include <cstdio>

char* intToStr(char* p, unsigned int n)
{
    char digit = n % 10 + '0'; 
    if (n /= 10)
    {
        p = intToStr(p,n);
    }
    else
    {
        *p = '\0';
    }
    
    
    *(p) = digit;
    p++;
    return p;
    
    

}
int main()
{

    unsigned int n = 1234;
    char p[50] = {};

    intToStr(p,n);
    printf("%s\n",p);
 
    return 0;


}
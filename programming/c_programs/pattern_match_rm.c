// a program to return the rightmost occurence of a pattern in a line
#define MAXLINE 1000

#include <stdio.h>
char pattern[] = "ould";
int getline_(char s[],int lim)
{
	int c,i;
	i=0;
	while(--lim > 0 && (c=getchar())!=EOF && c!='\n')
	{
		s[i++] = c;
	}
	if (c == '\n')
	    s[i++] = c;
	s[i] = '\0';
	return i;
}

int strindex(char s[], char t[])
{
    int i,j,k;
    int rightmost = -1;
    for (i=0;s[i]!='\0';i++)
    {
	for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
	;
	if (k > 0 && t[k]=='\0')
	{
	    rightmost=i;
	}
	i=i+k;

    }
    return rightmost;
}

int main()
{
    char line[MAXLINE];
    int found = 0;
    while(getline_(line,MAXLINE) > 0)
    {
	if (strindex(line,pattern) > 0)
	{
	    printf("rightmost position : %d\n", strindex(line,pattern));
	    printf("the line is %s", line);
	    found++;
	}
    }
    return found;
}
        

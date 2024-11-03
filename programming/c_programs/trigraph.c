/* this program is just for fun, in c code, you can replace some common characters with digraphs and trigraphs and still make it compile code */

??=include<stdio.h>
??=include<stdlib.h>

int main(void)
??<
    int xs??(??) = ??<1,2,3??>;
    for (int i=0;i<3;i++)
    {
	    printf("xs[i] = %d\n",xs??(i??));
    }
    return 0;
??>

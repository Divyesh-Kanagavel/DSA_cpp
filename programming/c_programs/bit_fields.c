/* a very useful idea : there are scenarios where i want to store values consuming bit level spacing. i.e
 say 2 bits for A, 2 bits for B together making up 4 bits of integer. Bit fields can be used instead of manually working with 
binary shifts */

#include <stdio.h>
#include <stdint.h>
#include<string.h>
struct bit_field
{
	int start_value : 4; // 4 bits
	int second_value : 4;// 4 bits
        int third_value : 2; // 2 bits
        int last_value : 6; // 6 bits 
};

int main()
{
	struct bit_field bf;
	/*
	there is a terrible bug here, while assigning values I assumed all 4 bits or 6 bits are available for use, but first bit 
	is the sign bit and the max value which can be used is 1 bit less than asigned in bit field in structure.
	bf.start_value = 13;
	bf.second_value = 9;
	bf.third_value = 3;
	bf.last_value = 36;
	*/
	bf.start_value = 7;
	bf.second_value = 5;
	bf.third_value = 1;
	bf.last_value = 19;


	printf("size of struct is %d\n", sizeof(bf));
	printf("the struct fields are : %d, %d, %d, %d\n", bf.start_value, bf.second_value, bf.third_value, bf.last_value);
	int i;
	memcpy(&i, &bf, sizeof(int));

	printf("%d\n", i);
	return 0;

}

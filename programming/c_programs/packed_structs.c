#include <stdio.h>
#include <stdint.h>
struct unpacked
{
	int8_t a;
	int32_t c;
	int16_t b;
	
};

struct packed
{
	int8_t a;
	int32_t c;
	int16_t b;
} __attribute__((packed)); // compiler symbol to pack the structure and remove padding -> better space management but not optimized for storing and loading

int main()
{
	struct unpacked f = {
		.a = 0x11,
		.b = 0x2222,
		.c = 0x33333333
	};
        struct packed f2 = {
		.a = 0x11,
		.b = 0x2222,
		.c = 0x33333333
	};
	printf("size of unpacked is : %lu\n", sizeof(f));
        printf("size of packed struct is %lu\n", sizeof(f2));
	uint8_t *f_as_bytes = (uint8_t *)&f;
	for(size_t i=0;i < sizeof(f);i++)
	{
	    printf("%x",f_as_bytes[i]);

	}
	printf("\n");
 	uint8_t *f2_as_bytes = (uint8_t *)&f2;
	for(size_t i=0;i < sizeof(f2);i++)
	{
	    printf("%x",f2_as_bytes[i]);
	}      
       	return 0;
}	

/* implementation of Bob Jenkin's oatt hashing function  which works well as a hashing function
for a good number of cases. ofcourse even this cannot prevent from collisions in case 
of malicious input tailored to drive collisions */

#include <stdio.h>
#include <stdlib.h>

#define hash_size(n) ((unsigned long)1 << (n))
#define hash_mask(n) (hash_size(n) - 1)


/* the bits here refer to the number of bits available to the hash function. 
if bits is n, the max index usable is 2^n-1*/
unsigned long oatt_hash(char* key, unsigned long n, unsigned long bits)
{
    unsigned long hash, i;
    for (hash=0,i=0;i<n;++i)
    {
        hash += key[i];
        /* introduction of avalanche effect, a small change in bit pattern 
        of input, can cause a large difference in hash function*/
        hash += (hash << 10); 
        /* xor operation introduces randomness and diffusion to prevent
        similar inputs having similar hash functions. this makes the distribution
        of keys among the buckets more robust. */
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    /* to curtail the hash in the desired bit range*/
    return hash & hash_mask(bits);

}
/* test example !*/
int main()
{
    long snowflake[] = {4,9,1,8,0,2};
    long snowflake2[] = {4,9,2,8,0,2};
    unsigned long code = oatt_hash((char*)snowflake, sizeof(snowflake), 17);
    unsigned long code2 = oatt_hash((char*)snowflake2, sizeof(snowflake), 17);
    
    printf("%lu\n", code);
    printf("%lu\n", code2);
    return 0;
}

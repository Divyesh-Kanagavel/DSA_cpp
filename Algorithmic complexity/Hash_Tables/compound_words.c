/*
You are to find all the two-word compound words in a dictionary. 
A two-word compound word is a word in the dictionary that is the 
concatenation of exactly two other words in the dictionary.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hash_size(n) ((unsigned long)1 << (n))
#define hash_mask(n) (hash_size(n) - 1)
#define NUM_BITS 17
#define WORD_LENGTH 16
/* oatt hash function is used to find the hash code for strings in the 
dictionary */
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

/* word node */
typedef struct word_node
{
    char** word; /* an array of word strings */
    struct word_node* next;
} word_node;

/* read the input word as a line */
char* read_line(unsigned length)
{
    char* line = malloc(length);
    if (line == NULL)
    {
        fprintf(stderr, "malloc error!\n");
        exit(1);
    }
    char ch;
    unsigned len = 0;
    while(((ch = getchar())!=EOF)&&ch!='\n')
    {
        line[len++] = ch;
        if (len == length)
        {
            length = length * 2;
            line = realloc(line, length);
            if(line == NULL)
            {
                fprintf(stderr, "realloc error!\n");
                exit(1);
            }
        }
        line[len] = '\0';
    }
    return line;
}

/* function to check if word is in hash table */
int in_hash_table(
    word_node* hash_table[],
    char* word,
    unsigned len
)
{
    unsigned word_code;
    word_node* word_ptr;
    word_code = oatt_hash(word, len, NUM_BITS);
    word_ptr = hash_table[word_code];
    while(word_ptr)
    {
        if (strlen(*(word_ptr->word))==len &&
            strncmp(*(word_ptr->word),word,len) == 0)
            return 1;
        word_ptr = word_ptr->next;
    }
    return 0;
}

/* identify the compound words */
void identify_compound_words(
    char* words[],
    word_node* hash_table[],
    unsigned total
)
{
    unsigned i,j;
    for (i=0;i<total;++i)
    {
        unsigned len = strlen(words[i]);
        for (j=1;j<len;++j)
        {
            if (
                in_hash_table(hash_table, words[i],j) &&
                in_hash_table(hash_table, &words[i][j], len-j)
            )
                {
                    printf("%s\n",words[i]);
                    break;
                }
        }
    }
}

/* the input is in sorted order. but hash tables populate based on hash code 
and the order is distrubed. so, we use an additional array to store the elements in order.*/
int main(void)
{
    /* hash table array */
    static word_node* hash_table[1<<NUM_BITS] = {NULL};
    /* array of words */
    static char* words[1<<NUM_BITS] = {NULL};
    char* word;
    word_node* word_ptr;
    word = read_line(WORD_LENGTH);
    unsigned length, hash_code;
    unsigned total = 0;
    while(*word)
    {
        words[total] = word;
        word_ptr = malloc(sizeof(word_node));
        if (word_ptr == NULL)
        {
            fprintf(stderr, "malloc error!\n");
            exit(1);
        }
        length = strlen(word);
        hash_code = oatt_hash(word, length, NUM_BITS);
        word_ptr->word = &words[total];
        word_ptr->next = hash_table[hash_code];
        hash_table[hash_code] = word_ptr;
        word = read_line(WORD_LENGTH);
        ++total;
    }
    identify_compound_words(words, hash_table, total);
    return 0;
}

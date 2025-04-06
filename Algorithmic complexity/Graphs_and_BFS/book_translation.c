/*
DMOJ problem ecna16d
You’ve written a new book in English, and you want to get the book translated into n other target languages.
You’ve found m translators. Each translator knows how to translate between two languages and will do the translation at a given cost. 
For example, a translator may know how to translate between Spanish and Bengali at a cost of $1,800.
this means that you could ask this translator to translate from Spanish to Bengali for $1,800 or Bengali to Spanish for $1,800.
To reach a given target language may require multiple translations. For example, you may want to translate your book from English to Bengali but have no translator between these two languages. 
You might instead have to translate from English to Spanish and then Spanish to Bengali.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_LANGS 101
#define WORD_LENGTH 16 /*max length of the language name*/

typedef struct edge
{
    int to_lang, cost;
    struct edge *next;
} edge;

typedef int board[NUM_LANGS];
typedef int positions[NUM_LANGS];

/* function to read a word from stdinput*/

char* read_word(int length)
{
    char* str;
    int ch;
    int len=0;
    str = (char*)malloc(length);
    if (str == NULL)
    {
        fprintf(stderr, "memory allocation error\n");
        exit(1);    
    }
    while(((ch=getchar())!=EOF) && ch!='\n' && ch!=' ')
    {
        str[len++] = ch;
        /*if size of lang reaches maxlen, realloc with 2*size*/
        if (len == length)
        {
            length *= 2;
            str = (char*)realloc(str, length);
            if (str == NULL)
            {
                fprintf(stderr, "memory reallocation error\n");
                exit(1);
            }
        }        
    }
    str[len] = '\0'; /* null terminate the string */
    return str;
}

/* function to find the index of a language in the array of languages */
int find_lang(char** lang_names, char* lang)
{
    int i=0;
    while(strcmp(lang_names[i], lang)!=0)
    {
        i++;
    }
    return i;
}

void add_position(int from_lang, int to_lang,
               positions new_position, int *num_new_positions,
               board min_cost)
{
    if (min_cost[to_lang] == -1)
    {
        min_cost[to_lang] = 1 + min_cost[from_lang];
        new_position[*num_new_positions] = to_lang;
        (*num_new_positions)++;
    }
}


void find_distance(edge* adj_list[], int num_targets, board min_cost)
{
    static board min_moves;
    static positions cur_position, next_position;
    int num_cur_positions, num_next_positions;
    int i, from_lang , added_lang, best;
    for(i=0;i<num_targets;++i)
    {
        min_moves[i] = -1; /* to track langs with min moves from current_lang*/
        min_cost[i] = -1; /* to track the cost of langs with same number of min_moves */
    }
    min_moves[0] = 0; /* cost to translate from english to english is 0*/
    cur_position[0] = 0; /* english is the source language*/
    edge* e;
    num_cur_positions= 1;
    while(num_cur_positions > 0)
    {
        num_next_positions = 0;
        for(i=0;i<num_cur_positions;++i)
        {
            from_lang = cur_position[i];
            e = adj_list[from_lang];
            while(e)
            {
                add_position(from_lang, e->to_lang, next_position,
                &num_next_positions, min_moves);
                e = e->next;
            }
        }
        /* find the next position with min_cost */
        for(i=0;i<num_next_positions;++i)
        {
            added_lang = next_position[i];
            e = adj_list[added_lang];
            best = -1;
            while(e)
            {
                /* since linked list is stored in reverse order*/
                if (min_moves[e->to_lang] + 1 == min_moves[added_lang] && 
                (best == -1 || e->cost < best))
                best = e->cost;

                e = e->next;
            }
            min_cost[added_lang] = best;

        }

        num_cur_positions = num_next_positions;
        for(i=0;i<num_next_positions;++i)
        {
            cur_position[i] = next_position[i];
        }

    }
}

void solve(int num_targets, board min_costs )
{
    int i, total_cost = 0;
    for(i=1;i<num_targets;++i)
    {
        if (min_costs[i] == -1)
        {
            printf("Impossible\n");
            return;
        }
        total_cost += min_costs[i];
    }
    printf("%d\n", total_cost);
}

/* the main function is the driver function of the program */
int main(void)
{
    /* an array of linked lists to store the edges */
    static edge* adj_list[NUM_LANGS] = {NULL};
    static char* lang_names[NUM_LANGS];
    int i, num_targets, num_translators, cost, from_index, to_index;

    char *from_lang, *to_lang;
    edge* e;
    static board min_cost;

    scanf("%d%d\n", &num_targets, &num_translators);
    lang_names[0] = "English"; /*the source language is always English */

    for(i=1;i<=num_targets;++i)
    {
        /* read the name of languages of interest */
        lang_names[i] = read_word(WORD_LENGTH);
    }

    for(i=0;i<num_translators;++i)
    {
        /* read the from language */
        from_lang = read_word(WORD_LENGTH);
        /* read the to language */
        to_lang = read_word(WORD_LENGTH);
        /* read the cost of translation*/
        scanf("%d\n", &cost);
        /* compute the from_lang's index */
        from_index = find_lang(lang_names,from_lang);
        /* compute the to_lang's index */
        to_index = find_lang(lang_names,to_lang);
        /* create a new edge and populate it*/
        e = (edge*)malloc(sizeof(edge));
        if (e == NULL)
        {
            fprintf(stderr, "memory allocation error\n");
            exit(1);
        }

        e->to_lang = to_index;
        e->cost = cost;
        /* add the edge to the list at the beginning, since it is easy and efficient*/
        e->next = adj_list[from_index];
        adj_list[from_index] = e;
        /* since the graph is undirected, we add the edge in the reverse direction as well*/
        e = (edge*)malloc(sizeof(edge));
        if (e == NULL)
        {
            fprintf(stderr, "memory allocation error\n");
            exit(1);
        }
        e->to_lang = from_index;
        e->cost = cost;

        e->next = adj_list[to_index];
        adj_list[to_index] = e;        
    }
    find_distance(adj_list, num_targets+1, min_cost); /*english included in the */
    solve(num_targets+1, min_cost);
    return 0;
}
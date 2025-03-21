/*n this problem, we are given a family tree and a specified distance d. 
The score for each node is the number of descendants it has at distance d. 
Our task is to output the nodes with high scores*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Node data structure for a general tree */
typedef struct node
{
    char* name;
    struct node** children;
    int num_children;
    int score; /*number of descendants at distance d*/
} node;

/*reading the input*/
/* we could have multiple nodes and we need a method to find if the name
exists in the nodes being tracked */
/* a faster way to do this search is to use a hash table */
node* find_node(node* nodes[],  int num_nodes, char* name)
{
    int i;
    for(i=0;i<num_nodes;++i)
    {
        if (strcmp(nodes[i]->name, name) == 0)
            return nodes[i];
    }
    return NULL; /*if not found*/
}

/* if the node is not found, we create a node with the name . a malloc_safe function
is used */

void* malloc_safe(int size)
{
    char* mem = malloc(size);
    if (mem == NULL)
    {
        fprintf(stderr, "malloc error!\n");
        exit(EXIT_FAILURE);
    }
    return mem;
}

node* new_node(char* name)
{
    node* n = malloc(sizeof(node));
    n->name = name;
    n->num_children = 0;
    return n;
}

#define MAX_NAME 10
int read_tree(node* nodes[], int num_lines)
{
    int i,j,num_children;
    char *parent_name, *child_name;
    node *parent, *child;
    int num_nodes = 0;

    for (i=0;i<num_lines;++i)
    {
        parent_name = malloc_safe(MAX_NAME+1);
        scanf("%s",parent_name);
        scanf("%d",&num_children);
        parent = find_node(nodes, num_nodes, parent_name);
        if (parent == NULL)
        {
            parent = new_node(parent_name);
            nodes[num_nodes] = parent;
            ++num_nodes;

        }
        else
            free(parent_name);
        
        parent->children = malloc_safe(num_children * sizeof(node));
        parent->num_children = num_children;
        for(j=0;j<num_children;++j)
        {
            child_name = malloc_safe(MAX_NAME+1);
            scanf("%s",child_name);
            child = find_node(nodes, num_nodes,child_name);
            if (child==NULL)
            {
                child = new_node(child_name);
                nodes[num_nodes] = child;
                ++num_nodes;
            }
            else
                free(child_name);
            parent->children[j] = child;
        }
    }
    return num_nodes;
}

/* calculate number of descendants at distance d */
/* There are a couple of rules : 
1. if the distance is 1, it is the number of children to the node
2. if distance > 1, it is number of descendants to children at distance d-1
Through this recursive relation, we could calculate the number of descendants at distance d*/

int count_descendants(node* n, int d)
{
    int total, i;
    if (d == 1)
        return n->num_children;
    total = 0;
    for(i=0;i<n->num_children;++i)
        total += count_descendants(n->children[i], d-1);
    return total;   
}

void all_descendants(node **nodes, int num_nodes, int d)
{
    int i;
    for(i=0;i<num_nodes;++i)
        nodes[i]->score = count_descendants(nodes[i],d);
}

/* need to sort the nodes based on the scores. if two nodes have 
same score, sort them alphabetically by name 
we will use qsort and write a compare function for that */

int compare(const void* a, const void* b)
{
    node* n1 = *(node**)a;
    node* n2 = *(node**)b;

    if (n1->score > n2->score)
        return -1;
    if (n1->score < n2->score)
        return 1;
    return strcmp(n1->name, n2->name);
}

void output_info(node* nodes[], int num_nodes)
{
    int i=0;
    while((i<3) && (i<num_nodes) && (nodes[i]->score > 0))
    {
        printf("%s %d\n", nodes[i]->name, nodes[i]->score);
        ++i;
        /* if there are more nodes with same score, print them all */
        while((i<num_nodes) && (nodes[i]->score == nodes[i-1]->score))
        {
            printf("%s %d\n", nodes[i]->name, nodes[i]->score);
            ++i;
        }
    }
}
#define MAX_NODES 1000
/* main function */
int main()
{
    int num_cases, case_num;
    int n,d,num_nodes;
    node** nodes = malloc_safe(MAX_NODES * sizeof(node));
    scanf("%d",&num_cases);
    for(case_num=1;case_num<=num_cases;++case_num)
    {
        printf("Tree %d:\n", case_num);
        scanf("%d %d", &n, &d);
        num_nodes = read_tree(nodes, n);
        all_descendants(nodes, num_nodes, d);
        qsort(nodes, num_nodes, sizeof(node*), compare);
        output_info(nodes ,num_nodes);
        if (case_num < num_cases)
            printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define HIGHEST 2000000000

typedef struct edge
{
    int to_node, percentage, superpipe;
    struct edge* next;
} edge;

/* testing feasibility - if liquid poured in root node is sufficient */
int can_feed(int node, double liquid, edge* adj_list[], int liquid_needed[])
{
    /* base case */
    edge* e;
    int ok;
    double down_pipe;
    if (liquid_needed[node]!=-1)
        return liquid >= liquid_needed[node];
    
    e = adj_list[node];
    ok = 1;
    while(e && ok)
    {
        down_pipe = liquid * e->percentage / 100;
        if (e->superpipe)
            down_pipe = down_pipe * down_pipe;
        if(!can_feed(e->to_node, down_pipe, adj_list, liquid_needed))
        {
            ok = 0;
        }
        e = e->next;
    }
    return ok;
}


void solve(edge* adj_list[], int liquid_needed[])
{
    double low = 0;
    double high = HIGHEST;
    double mid;

    while(high - low > 0.0001)
    {
        mid = (high + low)/2;
        if (can_feed(1, mid, adj_list, liquid_needed))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    printf("%.4f\n", high);
}

/* read the inputs */
int main(void)
{
    static edge* adj_list[MAX_NODES+1] = {NULL};
    static int liquid_needed[MAX_NODES+1];

    int i, from_node, to_node, percentage, superpipe, num_nodes;
    edge *e;
    /* scan the number of nodes*/
    scanf("%d", &num_nodes);

    for(i=0;i<num_nodes-1;i++)
    {
        scanf("%d%d%d%d", &from_node, &to_node, &percentage, &superpipe);
        e = malloc(sizeof(edge));
        if (e==NULL)
        {
            fprintf(stderr, "malloc error!\n");
            exit(1);
        }
        e->to_node = to_node;
        e->percentage = percentage;
        e->superpipe = superpipe;
        e->next = adj_list[from_node];
        adj_list[from_node] = e;
    }

    for(i=1;i<=num_nodes;i++)
    {
        scanf("%d", &liquid_needed[i]);
    }
    solve(adj_list, liquid_needed);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

/* Edge data structure */
typedef struct edge{
    int to_cell, length;
    struct edge *next;
} edge;

int find_time(
    edge* adjacency_list[],
    int num_cells,
    int from_cell,
    int exit_cell
){
    static int min_time[MAX_CELLS + 1];
    static int visited[MAX_CELLS + 1];
    int i, current_cell, min_unvisited_time, best_node;
    edge* e;

    // Initialize arrays
    for(i = 1; i <= num_cells; i++) {
        min_time[i] = -1;
        visited[i] = 0;
    }
    min_time[from_cell] = 0;

    // Dijkstra's algorithm
    for(i = 0; i < num_cells; i++) {
        // Find unvisited node with minimum time
        min_unvisited_time = -1;
        best_node = -1;
        for(current_cell = 1; current_cell <= num_cells; current_cell++) {
            if(!visited[current_cell] && min_time[current_cell] >= 0 && 
               (min_unvisited_time == -1 || min_time[current_cell] < min_unvisited_time)) {
                min_unvisited_time = min_time[current_cell];
                best_node = current_cell;
            }
        }
        
        if(best_node == -1) break;  // No more reachable nodes
        
        visited[best_node] = 1;
        
        // Update times through current best node
        e = adjacency_list[best_node];
        while(e) {
            if(!visited[e->to_cell]) {
                if(min_time[e->to_cell] == -1 || 
                   min_time[best_node] + e->length < min_time[e->to_cell]) {
                    min_time[e->to_cell] = min_time[best_node] + e->length;
                }
            }
            e = e->next;
        }
    }
    
    return min_time[exit_cell];
}

int main()
{
    static edge* adjacency_list[MAX_CELLS+1];
    int num_cases, case_num,i;
    int num_cells, num_edges, exit_cell, time_limit;
    int from_cell,to_cell,length;
    int total, min_time;
    edge *e;
    /*read the number of cases */
    scanf("%d", &num_cases);
    for(case_num=1; case_num<=num_cases;case_num++)
    {
        /* per case, read num of cells, exit cell, time limit and num edges*/
        scanf("%d%d%d", &num_cells, &exit_cell, &time_limit);
        scanf("%d", &num_edges);
        for(i=1;i<=num_cells;i++)
        {
            adjacency_list[i] = NULL;
        }
        /* for every edge, read the next cell, length and append 
        the details to the adjacency list*/
        for(i=0;i<num_edges;i++)
        {
            scanf("%d%d%d", &from_cell, &to_cell, &length);
            e = malloc(sizeof(edge));
            if (e == NULL)
            {
                fprintf(stderr, "malloc failed!\n");
                exit(EXIT_FAILURE);
            }
            e->to_cell = to_cell;
            e->length = length;
            e->next = adjacency_list[from_cell];
            adjacency_list[from_cell] = e;
        }
        /* call dijkstra algorithm to compute the shortest path to the exit cell for 
        every cell */
        total = 0;
        for(i=1;i<=num_cells;i++)
        {
            min_time = find_time(adjacency_list, num_cells, i , exit_cell);
            if (min_time >= 0 && min_time <= time_limit)
            {
                total++;
            }       
        }
        printf("%d\n", total);
        if (case_num < num_cases)
            printf("\n");       
    }
    return 0;
}
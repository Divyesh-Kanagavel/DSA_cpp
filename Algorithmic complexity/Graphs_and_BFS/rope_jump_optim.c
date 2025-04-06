/*
in the solution before, the bfs function is called once, but the number of 
edges especially during fall are very high. we have a fall edge of 1m below, 2m below 
and so on. 
We think of an alternate model where we have two ropes -> one for climbing up
with the same rules [including itching powder] and one for falling down, where from 
each node you are allowed to fall 1 m down. so, we are reducing the number of edges
but achieving the same functionality. 
Instead of a 1d array, we need a 2d array which holds position + state. */

#include <stdio.h>
#define SIZE 1000000
typedef struct position
{
    int height, state;
} position;

typedef int boards[SIZE*2][2];
typedef position positions[SIZE*4];


/*position_up : if the climber has to go up, what will be the change in his
state , position etc */
void position_up(int from_height, int to_height, int max_height, 
                    positions pos, int *num_pos, int itching[], boards min_moves)
{
    int distance = min_moves[from_height][0] + 1;
    if (to_height <= max_height && itching[to_height] == 0 && 
    (min_moves[to_height][0] == -1 || min_moves[to_height][0] > distance))
    {
        min_moves[to_height][0] = distance;
        pos[*num_pos].height = to_height;
        pos[*num_pos].state = 0;
        (*num_pos)++;
    }
}

/*position_down : if the climber has to fall down, what will be the change in his
state , position etc */

void position_down(int from_height, int to_height, positions pos,
                int *num_pos, boards min_moves){
    int distance = min_moves[from_height][1]; /*no cost to fall down and cur state is rope 1*/
    if (to_height >= 0 && (min_moves[to_height][1] == -1 || min_moves[to_height][1] > distance))
    {
        min_moves[to_height][1] = distance;
        pos[*num_pos].height = to_height;
        pos[*num_pos].state = 1;
        (*num_pos)++;
    }        

}

/*switch state 0 - 1 -> going from rope 0 to rope 1,at cost of 1*/
void switch_state01(int from_height,positions pos, int* num_pos, boards min_moves){
    int distance = min_moves[from_height][0] + 1;
    if (min_moves[from_height][1] == -1 || min_moves[from_height][1] > distance)
    {
        min_moves[from_height][1] = distance;
        pos[*num_pos].height = from_height;
        pos[*num_pos].state = 1;
        (*num_pos)++;
    }
}

/* switch from state 1 to state 0 -> no cost, but consider itching */

void switch_state10(int from_height,positions pos, int* num_pos, 
    int itching[], boards min_moves){
    
    int distance = min_moves[from_height][1];
    if ((min_moves[from_height][0] == -1 || min_moves[from_height][0] > distance) && itching[from_height] == 0)
    {
        min_moves[from_height][0] = distance;
        pos[*num_pos].height = from_height;
        pos[*num_pos].state = 0;
        (*num_pos)++;
    }
}

void find_distances(int target_height, int jump_distance,
int itching[], boards min_moves)
{
    static positions cur_position, next_position;
    int num_cur_positions, num_next_positions;
    int i, j, from_height, from_state;

    for(i=0;i<target_height*2;++i)
    {
        for(j=0;j<2;++j)
        {
            min_moves[i][j] = -1;
        }
    }
    min_moves[0][0] = 0;
    cur_position[0].height = 0;
    cur_position[0].state = 0;

    num_cur_positions = 1;

    while(num_cur_positions > 0)
    {
        num_next_positions = 0;
        for (i=0;i<num_cur_positions;++i)
        {
            from_height = cur_position[i].height;
            from_state = cur_position[i].state;
            if (from_state == 0)
            {
                position_up(from_height, from_height + jump_distance, 
                target_height * 2 - 1, next_position, &num_next_positions, 
            itching, min_moves);
                switch_state01(from_height, next_position, &num_next_positions, min_moves);
            }
            else
            {
                position_down(from_height, from_height-1, next_position, &num_next_positions,
                min_moves);
                switch_state10(from_height, next_position, &num_next_positions, itching, min_moves);
            }
        }
        num_cur_positions = num_next_positions;
        for(j=0;j<num_cur_positions;++j)
        {
            cur_position[j].height = next_position[j].height;
            cur_position[j].state = next_position[j].state;
        }
    }
}

void solve(int target_height, boards min_move)
{
    int i;
    int best = -1;
    /* the final destination could be anywhere between n and 2n, so we need to be careful */
    for(i=target_height; i < 2 * target_height; ++i)
    {
        if ((min_move[i][0]!=-1) && (best == -1 || min_move[i][0] < best))
        {
            best = min_move[i][0];
        }
    }
    printf("%d\n",best);
}

int main()
{
    int target_height, jump_distance,num_itching_sections;
    static int itching[SIZE*2] = {0};
    static boards min_moves;
    int i, j, itch_start, itch_end;
    scanf("%d%d%d", &target_height, &jump_distance, &num_itching_sections);
    for(i=0;i<num_itching_sections;++i)
    {
        scanf("%d%d", &itch_start, &itch_end);
        for(j=itch_start;j<=itch_end;++j)
        {
            itching[j] = 1;
        }
    }

    find_distances(target_height,jump_distance,itching,min_moves);

    solve(target_height,min_moves);
    return 0;

}







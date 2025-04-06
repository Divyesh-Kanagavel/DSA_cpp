/*
Bob is forced to climb a rope in gym class. The rope is infinitely long, but Bob is being asked to get only to a height of at least h meters.
Bob starts at a height of 0. He knows how to jump up by exactly j me- ters, but that’s the only jump he knows how to do—so if j is 5, then he can’t jump up four or six meters or any other number of meters except five. In addition, Bob knows how to fall, and he can fall down any number of meters: one, two, three, and so on.
Each jump or fall counts as one move. For example, if Bob jumps up five meters, falls down two meters, jumps up five meters, and falls down eight meters, then Bob will have made four moves.
Now, here’s the fun part: Alice has spread itching powder on some seg- ments of the rope. If such a segment goes from height a to height b, then the entire segment from a to b, including the endpoints a and b, has itching powder. The effect that the itching powder has on Bob’s moves is as follows:
• Bob cannot jump up j meters if that would land him on itching powder.
• Bob cannot fall down a given number of meters if that would land him on itching powder.
The goal is to determine the minimum number of moves needed for Bob to get to height h or higher.
*/
#include <stdio.h>

#define SIZE 1000000

/*typedefs*/
typedef int positions[SIZE*2]; /*at least h meters to be climbed. The maximum number of boxes till we search is 2h since the jump
distance j <= h. So, if we have a solution at 2h-1, meaning we have a solution within 1 and 2.*/
typedef int board[SIZE*2];

void add_position(int from_height,
int to_height, 
int range_max, 
int itching[],
positions next_position,
int *num_next_positions,
board min_moves)
{
    if (to_height <= range_max && min_moves[to_height]==-1 && itching[to_height] == 0)
    {   
        min_moves[to_height] = 1 + min_moves[from_height];
        next_position[*num_next_positions]  = to_height;
        (*num_next_positions)++; 
    }
} 

void find_distances(
    int target_height, 
    int jump_distance,
    int itching[],
    board min_moves)
{
    static positions cur_position, next_position;
    int num_cur_positions, num_next_positions;
    int i, j, from_height;
    for(i=0;i<target_height*2;++i)
    {
        min_moves[i] = -1;
    }
    cur_position[0] = 0;
    min_moves[0] = 0;
    num_cur_positions = 1;

    while(num_cur_positions > 0)
    {
        num_next_positions = 0;
        for(i=0;i<num_cur_positions; ++i)
        {
            from_height = cur_position[i];
            /*jump to a height j from current height*/
            add_position(from_height,
            from_height+jump_distance,
            target_height*2-1,
            itching,
            next_position,
            &num_next_positions,
            min_moves);

            /* fall to a height from j.*/
            for(j=0;j<from_height;++j)
            {
                add_position(from_height,
                j,
                target_height*2-1,
                itching,
                next_position,
                &num_next_positions,
            min_moves);
            }
        }
        num_cur_positions = num_next_positions;
        for(i=0;i<num_next_positions;++i)
        {
            cur_position[i] = next_position[i];
        }
    }
}

void solve(int target_height, board min_move)
{
    int i;
    int best = -1;
    /* the final destination could be anywhere between n and 2n, so we need to be carefulß*/
for(i=target_height; i <2 * target_height; ++i)
{
    if ((min_move[i]!=-1) && (best == -1 || min_move[i] < best))
    {
        best = min_move[i];
    }
}
printf("%d\n",best);
}

int main()
{
    int target_height, jump_distance,num_itching_sections;
    static int itching[SIZE*2] = {0};
    static board min_moves;
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
    solve(target_height,min_moves );
    return 0;

}

/*in a problem solved by BFS, there are two scopes for optimization
1. reduce the number of calls to BFS -> in our case , we have only one call
which computes min distance to all possible heights
2. reduce number of edges -> in our case, when submitted to online judge, 
we have TLE problem due to a large number of edges in the graph. */
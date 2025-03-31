/*
The board has r rows, with row 1 at the bottom and row r at the top. The board has c columns, with column 1 at the left and column c at the right.
The pawn and knight each start in some square of the board. The pawn moves first, then the knight moves, then the pawn, then the knight, and so on, until the game ends. For each turn, a move must be made: remaining at the current square is not an option.
The pawn has no choice on what move to make: for each of its turns, it moves up one square.
The knight, by contrast, has up to eight choices for each move.
The goal is to determine the best-case outcome for the knight and the number of knight moves required to produce that outcome.
*/

/*
the problem is solved using BFS. from the knight's starting position, we explore
possible moves at n=1, n=2 , n=3 and so on till we reach the pawn's position which could
be one, two or three moves away from its starting position
*/
#include <stdio.h>
/* struct : position */
typedef struct position
{
    int row, col;
} position;

#define MAX_ROWS 99
#define MAX_COLS 99

typedef int board[MAX_ROWS + 1][MAX_COLS + 1]; // distance of cell i,j from knight's starting point
typedef position positions[MAX_ROWS * MAX_COLS]; // position of knight

/* find distance from starting row, starting col to all rows, cols doing BFS
once we have the positions, we can retrive what we need for a particular position */
void add_position(int from_row,
    int from_col,
    int to_row,
    int to_col,
    int num_rows,
    int num_cols,
    int *num_next_positions,
    positions next_position,
    board min_moves)
{
if (to_row >=1 && to_col >= 1 && to_row <= num_rows && to_col <= num_cols 
&& min_moves[to_row][to_col]==-1)
{
min_moves[to_row][to_col] = 1 + min_moves[from_row][from_col];
next_position[*num_next_positions] = (position) {to_row, to_col};
(*num_next_positions)++;

}
}
void find_distance(int knight_row, int knight_col, int num_rows, int num_cols, board min_moves)
{
    positions cur_position, next_position;
    int num_cur_positions = 0;
    int num_next_positions = 0;
    int i, j, from_row, from_col;
    for(i=1;i<=num_rows;++i)
    {
        for(j=1;j<=num_cols;++j)
        {
            min_moves[i][j] = -1;
        }
    }

    min_moves[knight_row][knight_col] = 0;
    cur_position[0] = (position) {knight_row, knight_col};
    num_cur_positions = 1;

    while(num_cur_positions > 0)
    {
        num_next_positions = 0;
        for (i=0;i<num_cur_positions;++i)
        {
            from_row = cur_position[i].row;
            from_col = cur_position[i].col;

            /* add all possible knight moves from cur_position */
            add_position(from_row, from_col, from_row+1, from_col+2, num_rows, num_cols,
            &num_next_positions, next_position,min_moves);

            add_position(from_row, from_col, from_row+1, from_col-2, num_rows, num_cols,
                &num_next_positions, next_position,min_moves);
           
            add_position(from_row, from_col, from_row-1, from_col+2, num_rows, num_cols,
                &num_next_positions, next_position,min_moves);
                        
            add_position(from_row, from_col, from_row-1, from_col-2, num_rows, num_cols,
                &num_next_positions, next_position,min_moves);

            add_position(from_row, from_col, from_row+2, from_col-1, num_rows, num_cols,
                &num_next_positions, next_position,min_moves);

            add_position(from_row, from_col, from_row+2, from_col+1, num_rows, num_cols,
                &num_next_positions, next_position,min_moves); 
            
            add_position(from_row, from_col, from_row-2, from_col-1, num_rows, num_cols,
                    &num_next_positions, next_position,min_moves);
            
            add_position(from_row, from_col, from_row-2, from_col+1, num_rows, num_cols,
                    &num_next_positions, next_position,min_moves);
        }
        num_cur_positions = num_next_positions;
        for(i=0;i<num_next_positions;++i)
        {
            cur_position[i] = next_position[i];
        }
    }    
}



void solve(int num_rows, int num_cols, int knight_row, int knight_col,
            int pawn_row, int pawn_col)
{
    int cur_pawn_row, knight_takes, moves;
    board min_moves;
    cur_pawn_row = pawn_row;
    moves = 0;

    /* call the BFS once to populate the min_moves board */
    find_distance(knight_row, knight_col, num_rows, num_cols, min_moves);
    /* check for victory i.e capture of pawn by knight*/
    while(cur_pawn_row < num_rows)
    {
        knight_takes = min_moves[cur_pawn_row][pawn_col];

        /*knight_takes == moves seems the correct condition
        but it misses the case where knight could revisit the node it visited.
        this happens when moves-knight_takes is divisible by 2, because this 
        repetition is possible only for even additional moves */

        if (knight_takes >= 0 && moves >= knight_takes && ((moves - knight_takes)%2 == 0))
        {
            printf("Win in %d knight move(s).\n", moves);
            return;
        }

        cur_pawn_row++;
        moves++;
    }

    /* check for stalemate i,e knight infront of pawn */

    cur_pawn_row = pawn_row;
    moves = 0;
    while(cur_pawn_row < num_rows)
    {
        knight_takes = min_moves[cur_pawn_row+1][pawn_col];
        if (knight_takes >= 0 && moves >= knight_takes && ((moves - knight_takes)%2 == 0))
        {
            printf("Stalemate in %d knight move(s).\n", moves);
            return;
        }

        cur_pawn_row++;
        moves++;
    }
    /* loss i.e failure to capture or stalemaate*/
    printf("Loss in %d knight move(s).\n", num_rows - pawn_row - 1);
}

int main(void) 

{
    int num_cases, i;
    int num_rows, num_cols, pawn_row, pawn_col, knight_row, knight_col;
    scanf("%d", &num_cases);
    for (i = 0; i < num_cases; i++) {
      scanf("%d%d", &num_rows, &num_cols);
      scanf("%d%d", &pawn_row, &pawn_col);
      scanf("%d%d", &knight_row, &knight_col);
      printf("%d %d %d %d %d %d\n", num_rows, num_cols, pawn_row, pawn_col, knight_row, knight_col);
      solve(num_rows, num_cols, knight_row, knight_col, pawn_row, pawn_col);
    }
 return 0; }
 
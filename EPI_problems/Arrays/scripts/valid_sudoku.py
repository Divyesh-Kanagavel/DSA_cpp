# check if a partially filled sudoku is valid
import math
import collections 
def valid_sudoku(partial_assignment):

    def has_duplicate(block):
        block = list(filter(lambda x: x!=0, block))
        return len(block) != len(set(block))
    
    n = len(partial_assignment)
    # check row and column constraints
    if any(
        has_duplicate([partial_assignment[i][j] for j in range(n)]) or
        has_duplicate([partial_assignment[j][i] for j in range(n)])
        for i in range(n)):
        return False
    # region constraints

    region_size = int(math.sqrt(n))
    return all(
        not has_duplicate([
            partial_assignment[a][b]
            for a in range(region_size * I, region_size * (I+1))
            for b in range(region_size * J, region_size * (J+1))
        ]) for I in range(region_size) for J in range(region_size)
    )

def valid_sudoku_shorter(partial_assignment):
    region_size = int(math.sqrt(len(partial_assignment)))
    return max(
        collections.Counter(
           k for i, row in enumerate(partial_assignment)
           for j, c in enumerate(row)
           if c!=0
           for k in (
               (i, str(c)),
               (str(c), j),
               (i / region_size, j / region_size, str(c))
           )
        ).values(),default=0
    ) <= 1


#test
if __name__ == "__main__":
    sud = [[5,3,0,0,7,0,0,0,1],
           [6,0,0,1,9,5,0,0,0],
           [0,9,8,0,0,0,0,6,0],
           [8,0,0,0,6,0,0,0,3],
           [4,0,0,8,0,3,0,0,1],
           [7,0,0,0,2,0,0,0,6],
           [0,6,0,0,0,0,2,8,0],
           [0,0,0,4,1,9,0,0,5],
           [0,0,0,0,8,0,0,7,9]]
    
    print(valid_sudoku(sud))
    print(valid_sudoku_shorter(sud))
    



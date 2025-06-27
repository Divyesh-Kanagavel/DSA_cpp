# Write a program which takes an n x n 2D array and retums the spiral ordering of the array.

def matrix_in_spiral_order(square_matrix):
    def matrix_layer_in_clockwise(offset):
        # check for last element
        if offset == len(square_matrix) - offset - 1:
            spiral_ordering.append(square_matrix[offset][offset])
            return
        # first row [0 to N-1]
        spiral_ordering.extend(square_matrix[offset][offset:-1-offset])
        # last column [0 to N-1]
        spiral_ordering.extend(
            list(zip(*square_matrix))[-1-offset][offset:-1-offset]
        )
        # last row [N-1 to 0]
        spiral_ordering.extend(
            square_matrix[-1-offset][-1-offset:offset:-1]
        )
        # first column [N-1 to 0]
        spiral_ordering.extend(
            list(zip(*square_matrix))[offset][-1-offset:offset:-1]
        )
    
    spiral_ordering = []
    for offset in range((len(square_matrix) + 1) // 2):
        matrix_layer_in_clockwise(offset)
    
    return spiral_ordering

def matrix_in_spiral_order_single(square_matrix):
    SHIFT = ((0,1), (1,0), (0,-1), (-1,0))
    direction = x = y = 0
    spiral_ordering = []
    size = len(square_matrix)

    for i in range(size ** 2):
        spiral_ordering.append(square_matrix[x][y])
        square_matrix[x][y] = 0 # assuming 0 is not there in square matrix
        next_x, next_y = x + SHIFT[direction][0], y + SHIFT[direction][1]
        outside_x = next_x not in range(size)
        outside_y = next_y not in range(size)
        if not outside_x and not outside_y:
            exists = square_matrix[next_x][next_y]

        if outside_x or outside_y or exists == 0:
            direction = (direction + 1) & 3
            next_x, next_y = x + SHIFT[direction][0], y + SHIFT[direction][1]
    
        x,y = next_x, next_y
    return spiral_ordering

            


# test
if __name__ == "__main__":
    matrix = [[1,2,3],[4,5,6],[7,8,9]]
    print(matrix_in_spiral_order(matrix))
    print(matrix_in_spiral_order_single(matrix))

        
    
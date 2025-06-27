# Access a mXn array in spiral order

def spiralmXn(arr):
    n_rows = len(arr)
    n_cols = len(arr[0])
    spiral_order = []
    SHIFT = ((0,1),(1,0),(0,-1),(-1,0))
    direction = x = y = 0

    for _ in range(n_rows * n_cols):
        spiral_order.append(arr[x][y])
        arr[x][y] = 0 # assume 0 is not there in arr. else, use some other number not in arr
        next_x ,next_y = x + SHIFT[direction][0] , y + SHIFT[direction][1]
        outside_x = next_x not in range(n_rows)
        outside_y = next_y not in range(n_cols)
        if not outside_x and not outside_y:
            exists = arr[next_x][next_y]
        if outside_x or outside_y or exists == 0:
            direction = (direction + 1) & 3
            next_x, next_y = x + SHIFT[direction][0], y + SHIFT[direction][1]
        x,y = next_x, next_y
    
    return spiral_order

if __name__ == "__main__":
    arr = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    print(spiralmXn(arr))
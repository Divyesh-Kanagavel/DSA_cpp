'''
Here is a solution to the “Unique Paths” problem
Optimize it using memoization
'''

def unique_paths(rows, columns):
    if rows == 1 or columns == 1:
        return 1
    return unique_paths(rows - 1, columns) + unique_paths(rows, columns - 1)

print(unique_paths(3,3))


def unique_paths_memoized(rows, columns, memo = {}):
    if rows == 1 or columns == 1:
        return 1
    if not memo.get((rows,columns)):
        memo[(rows,columns)] = unique_paths_memoized(rows - 1, columns, memo) + unique_paths_memoized(rows, columns - 1, memo)
    return memo[(rows,columns)]

# equivalency test
bool = True
for i in range(1,10):
    for j in range(1,10):
        if (unique_paths(i,j) != unique_paths_memoized(i,j)):
            bool = False
            break
print(bool)


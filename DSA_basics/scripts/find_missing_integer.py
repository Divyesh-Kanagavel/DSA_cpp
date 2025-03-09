#problem
#You’re writing a function that accepts an array of distinct integers from 0, 1, 2, 3...up to N. However, the array will be missing one integer, and your function is to return the missing one.
# time complexity - O(N)
def find_missing_integer(arr):
    n = len(arr)
    sum_arr = 0
    for i in arr:
        sum_arr += i 
    sum = n * (n+1) / 2

    return int(sum - sum_arr)

arr = [8, 2, 3, 9, 4, 7, 5, 0, 6]
print(find_missing_integer(arr))
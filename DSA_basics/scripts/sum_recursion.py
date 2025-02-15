# sum numbers in an array through recursion

def sum_numbers(arr):
    if len(arr) == 1:
        return arr[0]
    return arr[0] + sum_numbers(arr[1:])

def sum_numbers_wrapper(arr):
    if arr is None:
        return 0
    if len(arr) == 0:
        return 0
    return sum_numbers(arr)

print(sum_numbers_wrapper(None))
print(sum_numbers_wrapper([]))
print(sum_numbers_wrapper([4]))
print(sum_numbers_wrapper([3,4,5,0,-1,9]))
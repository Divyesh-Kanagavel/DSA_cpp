# given an array of numbers, return a new array of even numbers using recursion

def even_array(arr):
    if arr is None:
        return None
    if len(arr) == 0:
        return []
    if arr[0] % 2 == 0:
        return [arr[0]] + even_array(arr[1:])
    return even_array(arr[1:])

print(even_array([1,2,3,4,5]))
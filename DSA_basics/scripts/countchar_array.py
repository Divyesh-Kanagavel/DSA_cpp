# count total number of characters in an array of string using recursion

def count_char(arr):
    if arr is None:
        return None
    if len(arr) == 0:
        return 0
    if len(arr) == 1:
        return len(arr[0])
    return len(arr[0]) + count_char(arr[1:])

print(count_char(["ab", "c", "def", "ghij"],))
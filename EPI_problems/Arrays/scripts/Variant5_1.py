# Implement a function which takes as input an array and a key, and updates the array so
# that all occurrences of the input key have been removed and the remaining elements have been
# shifted left to fill the emptied indices. Return the number of remaining elements. There are no
# requirements as to the values stored beyond the last valid element.

def remove_key(arr,key):
    if not arr:
        return 0
    write_index = 0
    for i in range(len(arr)):
        if arr[i]!=key:
            arr[write_index] = arr[i]
            write_index += 1
    
    return write_index

#tests
if __name__ == "__main__":
    arr = [1,2,5,1,9,7,7,8,5,4,7,8]
    key = 1
    write_index = remove_key(arr, key)
    print(arr[:write_index])
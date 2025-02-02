# Notes
'''
Hash tables are not faster and convenient in cases where data is paired.
They can also be used in places where we need to store indices of elements. 
They can save on nested loops to find existence of elements / subarrays through direct hash mapping
'''
# example : find existence of subarray in an array
# approach 1 : loop through the smaller array and check if each element exists in the larger array. O(n^2)

def subarray_exists(arr1,arr2):
    if len(arr1) > len(arr2):
        arr1,arr2 = arr2,arr1
    for i in arr1:
        if i not in arr2:
            return False
    
    return True

# approach 2 : use hash table to store elements of the larger array. O(n) time complexity

def subarray_existshash(arr1, arr2):
    if (len(arr1) > len(arr2)):
        arr1,arr2 = arr2,arr1
    
    hash_table = {}
    for i in arr2:
        hash_table[i] = True
    
    for i in arr1:
        if not hash_table.get(i):
            return False
    
    return True

# test cases

arr1 = [4,9,8,2,1]
arr2 = [9,4,7,1,2,3,5,6,8]
arr3 = [11,12]
print(subarray_exists(arr1,arr2))
print(subarray_exists(arr3,arr2))

print(subarray_existshash(arr1,arr2))
print(subarray_existshash(arr3,arr2))
# This problem is concemed with deleting repeated elements from a sorted array. For example, for
# the array <2,3,5,5,7,1.1.,L1.,77,73>, then after deletion, the array is (2,3,5,7,77,73,0,0,0). After
# deleting repeated elements, there are 6 valid entries. There are no requirements as to the values
# stored beyond the last valid element.
# There is an O(n) time and O(1) space solution.
# we need to delete the duplicate and shift the succeeding elements to the left
# by one position. brute force approach is to pass through A, check A[i] with 
# A[i+1], if there is duplicate, shift all n+1 elements to the left. this involves
# n+n-1+n-2...1 elements in the worst case, O(n^2). We can definitely do better
def delete_duplicates(arr):
    if not arr:
        return 0
    
    write_index = 1
    for i in range(1, len(arr)):
        if arr[write_index-1]!=arr[i]:
            arr[write_index] = arr[i]
            write_index+=1
    return write_index

# tests
if __name__ == "__main__":
    arr = [2,3,5,5,7,7,8,9,10,10,11,12,12,12]
    write_index = delete_duplicates(arr)
    print(arr[:write_index])

    
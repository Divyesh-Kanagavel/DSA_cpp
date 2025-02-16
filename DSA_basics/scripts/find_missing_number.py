#Exercise
'''
The following function finds the “missing number” from an array of integers. 
That is, the array is expected to have all integers from 0 up to the array's length, but one is missing. 
As examples, the array, [5, 2, 4, 1, 0] is missing the number 3, and the array, [9, 3, 2, 5, 6, 7, 1, 0, 4] is missing the number 8.
'''

def find_missing_number(arr):
    if len(arr) == 0:
        print("array is empty")
        return -1
    if len(arr) == 1:
        print("array contains only one element")
        return -1
    arr.sort()
    for i in range(len(arr)):
        if arr[i]!=i:
            return i
    
arr= [1,2,3,4,5]
print(find_missing_number(arr))
    
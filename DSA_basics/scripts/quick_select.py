# let us say we do not need to sort the entire array but we need to 
# find the kth smallest/largest element in the array
# quickselect proves handy. it is also a divide and conquer algorithm
# it makes use of partition function used in quick sort. 

# on average, it has a time complexity of O(N). the partition takes O(N) to find the pivot index and return
# and we will be throwing away the subarray where our kth element will not be there. 
# so, on average , we may have to do N + N/2 + N/4 + N/8 ... operations = 2N

def partition(arr, left_pointer, right_pointer):
    pivot_index = right_pointer # any index could be chosen as pivot
    pivot = arr[pivot_index]
    right_pointer -= 1
    while True:
        while arr[left_pointer] < pivot:
            left_pointer+=1
        while arr[right_pointer] > pivot:
            right_pointer -= 1
        if left_pointer >= right_pointer:
            break
        else:
            arr[left_pointer], arr[right_pointer] = arr[right_pointer], arr[left_pointer]
            left_pointer += 1
    arr[left_pointer], arr[pivot_index] = arr[pivot_index], arr[left_pointer]
    return left_pointer

def quickselect(arr,index):
    if index >= len(arr):
        return -1
    left_pointer =0
    right_pointer = len(arr)-1
    while True:
        pivot_index = partition(arr, left_pointer, right_pointer)
        if pivot_index == index:
            return arr[pivot_index]
        elif pivot_index > index:
            right_pointer = pivot_index-1
        else:
            left_pointer = pivot_index + 1

arr = [8,1,0,11,45,3,7]
print(quickselect(arr,3))    


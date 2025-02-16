# quick sort algorithm implementation in python
# quick sort is a divide and conquer algorithm which relies on recursion
# it has a average time complexity of O(nlogn)
# it is much faster than bubble , insertion and selection sort on average
# in the worst case, the time complexity is O(n^2)

# the first step is to implement partition function
# the partition function is used to partition the array into two parts
# the first part contains all the elements that are less than the pivot
# the second part contains all the elements that are greater than the pivot
# the pivot is the element that is being compared with the elements in the array

import random 
import time

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
    return left_pointer # returned for quick sort function

# once we have partition method, we have a way of diving the array into two parts
# so, keep dividing the subarrays this way till you reach base condition - when length is 0 or 1.
def quicksort(arr, left_index, right_index):
    if left_index >= right_index:
        return 
    pivot_index = partition(arr, left_index,right_index)
    quicksort(arr, left_index,pivot_index-1)
    quicksort(arr, pivot_index+1, right_index)


# test
arr = [8,4,0,3,2,9]
quicksort(arr,0,len(arr)-1)
print(arr)

# some tests to compare efficiency of quick sort and python's build in implementation
SIZE = 100000
# 1. average case
arr = [random.randint(0,1000) for _ in range(SIZE)]
# python sort time
arr1 = arr.copy()
start_time = time.time()
arr1.sort()
end_time = time.time()
print("python's sort function time : average case = ", end_time-start_time)

arr2 = arr.copy()
start = time.time()
quicksort(arr2, 0, len(arr2)-1)
end_time = time.time()
print("Quicksort function time : average case = ", end_time-start_time)

# 2. Best case
arr = [range(0,SIZE)]
arr1 = arr.copy()
start_time = time.time()
arr1.sort()
end_time = time.time()

print("python's sort function time : best case = ", end_time-start_time)

arr2 = arr.copy()
start_time = time.time()
quicksort(arr2, 0, len(arr2)-1)
end_time = time.time()
print("Quicksort function time : best case = ", end_time-start_time)



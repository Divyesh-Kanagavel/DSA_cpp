# given a pivot, reorder the array such that elements less than pivot appear first,
# elements equal to pivot appear next and the elements after the pivot appear last
import copy
# naive approach with O(n) space and time complexity
def naive_paritition(arr, pivot_index):
    before_pivot = []
    equal_pivot = []
    after_pivot = []
    pivot = arr[pivot_index]
    for i in arr:
        if i < pivot:
            before_pivot.append(i)
        elif i == pivot:
            equal_pivot.append(i)
        else:
            after_pivot.append(i)
    return before_pivot + equal_pivot + after_pivot

# this can be solved in O(1) space complexity
def dutch_flag_partition1(arr, pivot_index):
    pivot = arr[pivot_index]
    smaller = 0
    for i in range(len(arr)):
        if arr[i] < pivot:
            arr[smaller], arr[i] = arr[i], arr[smaller] # swap the elements
            smaller += 1
    
    larger = len(arr) - 1
    for i in reversed(range(len(arr))):
        if arr[i] < pivot:
            break
        if arr[i] > pivot:
            arr[larger], arr[i] = arr[i], arr[larger]
            larger -= 1

# we can improve the code further -> a single can is enough to partition the array
# Keep the following invariants during partitioning:
# bottom group: A[:smaller].
# middle group: A[smaller:equal].
# unclassified group: A[equal: larger]
# top group: A[larger:]
def dutch_flag_partition2(arr, pivot_index):
    pivot = arr[pivot_index]
    smaller, equal, larger = 0,0,len(arr)-1
    while equal < larger:
        if arr[equal] < pivot:
            arr[equal], arr[smaller] = arr[smaller], arr[equal]
            smaller += 1
            equal += 1
        elif arr[equal] == pivot:
            equal += 1
        else: # arr[equal] > pivot
            arr[equal], arr[larger] = arr[larger], arr[equal]
            larger -= 1   

if __name__ == "__main__":
    A = [3,6,9,1,0,2,1,7,0]
    n = 3
    A1 = copy.deepcopy(A)
    partitioned = naive_paritition(A1,n)
    print(partitioned)
    A2 = copy.deepcopy(A)
    dutch_flag_partition1(A2,n)
    print(A2)
    A3 = copy.deepcopy(A)
    dutch_flag_partition2(A3, n)
    print(A3)
    
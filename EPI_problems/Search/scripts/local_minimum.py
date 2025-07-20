# Let A be an unsorted array of n integers, with A[0] > A[1] and Aln - 2) < A[n - 11. Call an
# index I a local minimum if AU] is less than or equal to its neighbors. How would you efficiently find
# a local minirnum, if one exists?

# the idea is to check the condition A[n-1] > A[n] and A[n] < A[n+1]. then it is a local minimum
# if A[n-1] < A[n] < A[n+1] meaning it is ascending, so we move towards left using the same logic as binary searcj
# if A[n-1] > A[n] > A[n+1] meaning it is descending, so, we move towards right

def find_local_minima(arr):
    l, u = 1, len(arr)-2
    while l<=u:
        mid = l + (u-l)//2
        if arr[mid-1] > arr[mid] and arr[mid+1] > arr[mid]:
            return mid # one of the local minima
        elif arr[mid-1] < arr[mid] and arr[mid] < arr[mid+1]:
            u = mid - 1
        else:
            l = mid + 1
    return -1

if __name__ == "__main__":
    test1 = [9, 3, 5, 7, 8]
    test2 = [10, 5, 6, 3, 7, 2, 8]
    print(find_local_minima(test2))
# Write a program which takes a sorted anay A of integers, and an integer k, and refurns
# the interval enclosing k, i.e., the pair of integers L and U such that L is the first occurrence of k in
# A and U is the last occurrence of k in A. If k does not appear in A, return [-1, -1]
import bisect
def find_range_k(arr, k):
    l, u, result1= 0, len(arr)-1, -1
    while l<=u:
        mid = l + (u-l)//2
        if arr[mid] > k:
            u = mid - 1
        elif arr[mid] < k:
            l = mid + 1
        else:
            result1 = mid
            u = mid - 1
    l, u, result2= 0, len(arr)-1, -1
    while l<=u:
        mid = l + (u-l)//2
        if arr[mid] > k:
            u = mid - 1
        elif arr[mid] < k:
            l = mid + 1
        else:
            result2 = mid
            l = mid + 1
    if result1 == -1:
        return [-1, -1]
    return [result1, result2]

def find_range_k_pythonic(arr, k):
    left = bisect.bisect_left(arr, k)
    right = bisect.bisect_right(arr, k) - 1
    if left <= right and left < len(arr) and arr[left] == k:
        return [left, right]
    else:
        return [-1, -1]


if __name__ == "__main__":
    arr = [1,2,2,4,4,4,7,11,11,13]
    k = 2
    range_k = find_range_k(arr, k)
    print(range_k)
    range_k = find_range_k_pythonic(arr, k)
    print(range_k)
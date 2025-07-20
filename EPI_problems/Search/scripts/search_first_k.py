# Write a method that takes a sorted array and a key and retums the index of the first occurrence of
# that key in the array. Retum -1 if the key does not appear in the array.

def first_occurence_search(arr, k):
    l, u, result = 0, len(arr)-1, -1
    while l<=u:
        mid = l + (u-l)//2
        if arr[mid] < k:
            l = mid + 1
        elif arr[mid] > k:
            u = mid - 1
        else:
            result = mid
            u = mid - 1 # solution cannot be to the right of mid
    return result

def first_occurence_search_greater(arr, k):
       l, u, result = 0, len(arr)-1, -1
       while l<=u:
        mid = l + (u-l)//2
        if arr[mid] < k:
            l = mid + 1
        elif arr[mid] > k:
            u = mid - 1
        else:
            result = mid
            l = mid + 1 # solution cannot be to the right of mid
       return result if result == -1 else result + 1
 
if __name__ == "__main__":
    arr = [-14, -10, 2, 108,108,243, 285,285, 285, 401]
    k = -13
    print(first_occurence_search_greater(arr, k))

# Given an array A of n objects with keys that takes one of four values, reorder the array so
# that all objects that have the same key appear together. Use O(1) additional space and O(n) time.
# let the possible values be (0,1,2,3)

# this one is the solution which i thought of. works for some cases i tested
# but could fail in edge cases TODO : thoroughly test it
def reorder(arr):
    if max(arr) > 3 or min(arr) < 0:
        raise ValueError("only one of 0,1,2 or 3 values possible")
    
    zero, one, two, three = 0,0,len(arr)-1, len(arr)-1
    while one <= two:
        if arr[one] == 0:
            arr[zero], arr[one] = arr[one], arr[zero]
            zero += 1
            one += 1
        elif arr[one] == 1:
            one += 1
        elif arr[one] == 2:
            arr[one], arr[two] = arr[two],arr[one]
            two -= 1
        elif arr[one] == 3:
            arr[one], arr[three] = arr[three], arr[one]
            three -= 1
            two -= 1

# a more robust solution is to use two-pass modified DNF
def reorder_two_pass(arr):
    # in the first pass, reorder the array into two paritions
    # 0 and 1s to the left and 2 and 3s to the right
    left = 0
    right = len(arr)-1
    while left <= right:
        if arr[left] <= 1:
            left += 1
        else:
            arr[left],arr[right] = arr[right], arr[left]
            right -= 1
    
    # now sort the left parition , 0s to the left and 1s to the right
    ptr0 = 0
    ptr1 = left - 1
    while ptr0 <= ptr1:
        if arr[ptr0] == 0:
            ptr0 += 1
        else:
            arr[ptr0], arr[ptr1] = arr[ptr1], arr[ptr0]
            ptr1 -= 1
    
    # now sort the right partition grouping 2s to the left and 3s to the right
    ptr0 = left
    ptr1 = len(arr)-1
    while ptr0 <= ptr1:
        if arr[ptr0] == 2:
            ptr0 += 1
        else:
            arr[ptr0], arr[ptr1] = arr[ptr1], arr[ptr0]
            ptr1 -= 1

if __name__ == "__main__":
    A = [3,2,1,0,1,0,0,0,2,2,1,1,2,3,0,3,3]
    reorder_two_pass(A)
    print(A)
        






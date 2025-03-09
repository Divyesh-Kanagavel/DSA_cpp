# reverse an array in O(1) space complexity

def reverse(arr):
    n = len(arr)
    for i in range(n//2):
        arr[i],arr[n-i-1] = arr[n-i-1], arr[i]

arr = [1,4,5,6,7,0,9]
reverse(arr)
print(arr)
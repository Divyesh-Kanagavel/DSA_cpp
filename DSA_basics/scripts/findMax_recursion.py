# find max of a number in an array using recursion

# naive recursion
def findMax(arr):
    if arr is None or len(arr) == 0:
        return None
    # print to determine how many times recursion is called
    print("Recursion")
    # base case
    if len(arr) == 1:
        return arr[0]
    if arr[0] > findMax(arr[1:]):
        return arr[0]
    else:
        return findMax(arr[1:])

arr = [1,2,3,4]
print(findMax(arr))

# the above method is Naive and inefficient. the recursive function is called once 
# during comparison with arr[0] and then to return in else. this triggers a chain of function calls
# giving a time complexity of O(2^N)

# optimized recursion
def findMaxOptimized(arr):
    if arr is None or len(arr) == 0:
        return None
    # print to determine how many times recursion is called
    print("Recursion")
    # base case
    if len(arr) == 1:
        return arr[0]
    max = findMaxOptimized(arr[1:])
    if arr[0] > max:
        return arr[0]
    else:
        return max


arr = [1,2,3,4]
print(findMaxOptimized(arr))

# a simple hack of putting the recursion result to a variable and using it 
# for comparison and returning results in a time complexity of O(N). 

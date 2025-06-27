# Assuming that keys take one of three values, reorder the array so that all objects with the
# same key appear together. The order of the subarrays is not important

# solution in O(1) space complexity and O(N) time complexity is possible
import copy
# the three values possible are 0 , 1 or 2
def reorder(arr):
    if max(arr) > 2 or min(arr) < 0:
        raise ValueError("only one of 0,1 or 2 values possible")
    
    one, two, three = 0,0,len(arr)-1
    while two <= three:
        if arr[two] == 0:
            arr[one], arr[two] = arr[two], arr[one]
            one += 1
            two += 1
        elif arr[two] == 1:
            two += 1
        else: # arr[two] == 2
            arr[two], arr[three] = arr[three], arr[two]
            three -= 1

if __name__ == "__main__":
    A = [1,0,0,1,0,1,2,2,2,0,0,1,2]
    A1 = copy.deepcopy(A)
    reorder(A1)
    print(A1)
        

        

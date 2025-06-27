# Write a program which takes as input an array of digits encoding a nonnegative decimal integer
# D and updates the array to represent the integer D + 1. For example, if the input is (7,2,9) then
# you should update the array to (1,3,0). Your algorithm should work even if it is implemented in a
# language that has finite-precision arithmetic.

# brute force solution is to pass through the array , get the number and then increment it by 1
# and encode it back to an array
# the above approach will fail if implemented in a language which has finite precision arithmetic
# let us say we have a int32 integer, so, anything above the limit will cause overflow issues
# So, a more robust solution is to work on the array itself manipulating the elements in the array

def plus_one(arr):
    arr[-1] += 1 # adding one to the last member
    # we need to check if there is a carry and handle the carry
    # all the way till the first member if required
    for i in reversed(range(1, len(arr))):
        if arr[i]!=10:
            break
        arr[i] = 0
        arr[i-1] += 1
    if arr[0] == 10 : # if the first element is 10, need to add a digit
        arr[0] = 1
        arr.append(0) # increase the size of the array by 1
    
if __name__ == "__main__":
    num = [9,9,9]
    plus_one(num)
    print(num)

'''
The following function accepts an array of numbers and returns the sum, as long as a particular number doesn't bring the sum above 100.
If adding a particular number will make the sum higher than 100, that number is ignored.
However, this function makes unnecessary recursive calls. 
Fix the code to eliminate the unnecessary recursion
'''

def add_until_100(arr):
    if len(arr) == 0:
        return 0
    if arr[0] + add_until_100(arr[1:]) > 100:
        return add_until_100(arr[1:])
    return arr[0] + add_until_100(arr[1:])

# test
arr = [10,20,30,40,50]
print(add_until_100(arr))

# better version
def add_until_100_better(arr):
    if len(arr) == 0:
        return 0
    prev_sum = add_until_100_better(arr[1:])
    if arr[0] + prev_sum > 100:
        return prev_sum
    return arr[0] + prev_sum

# test
arr = [10,30,90]
print(add_until_100_better(arr))
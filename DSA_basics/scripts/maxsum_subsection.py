# We’re going to write a function that accepts an array of numbers and returns the largest sum that could be computed from any “subsection” of the array.

def max_sum(arr):
    current_sum = 0
    greatest_sum = 0

    for num in arr:
        if current_sum + num > 0:
            current_sum += num
        else:
            current_sum = 0
        
        if current_sum > greatest_sum:
            greatest_sum = current_sum
    
    return greatest_sum

arr = [3,-4,4,-3,5,-9]
print(max_sum(arr))
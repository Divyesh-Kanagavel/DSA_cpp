# Exercise
'''
Given an array of positive numbers, write a function that returns the greatest product of any three numbers. 
The approach of using three nested loops would clock in at O(N3), which is very slow. 
Use sorting to implement the function in a way that it computes at O(N log N) speed. 
(There are even faster implementations, but we're focusing on using sorting as a technique to make code faster.)
'''

def product_three_numbers(arr):
    if len(arr) < 3:
        print("length of array should be at least 3")
        return -1
    if not all(x > 0 for x in arr):
        print("all elements should be positive")
        return -1
    # first sort the array
    arr.sort()
    # now the largest elements are all at the end of the array
    # and product has to be product of those three numbers in the end [since they are positive]
    return arr[-1] * arr[-2] * arr[-3]

arr = [4,9,10,1,6,8,7,9]
print(product_three_numbers(arr))


# given an array of numbers , find the greatest product obtained by multiplying two numbers
# time complexity : O(n), space complexity : O(1)

import math

def find_greatest_product(arr):
    greatest_number = -math.inf
    second_greatest_number = -math.inf

    lowest_number = math.inf
    second_lowest_number = math.inf

    for num in arr:
        if num > greatest_number:
            second_greatest_number = greatest_number
            greatest_number = num
        elif num > second_greatest_number:
            second_greatest_number = num
        
        if num <= lowest_number:
            second_lowest_number = lowest_number
            lowest_number = num
        elif num > lowest_number and num < second_lowest_number:
            second_lowest_number = num
    
    product1 = greatest_number * second_greatest_number
    product2 = lowest_number * second_lowest_number

    return max(product1, product2)

arr = [5, -10, -6, 9, 4]
print(find_greatest_product(arr))

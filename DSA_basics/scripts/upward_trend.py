# we’re writing a function that accepts an array of stock prices and determines whether there are any three prices that create an upward trend.

# Naive approach : use three nested loops and check if there are three elements such that lower < middle < higher in the array
import math

def upward_trend(arr):
    lower_price = arr[0]
    middle_price = math.inf

    for num in arr:
        if num <= lower_price:
            lower_price = num
        elif num <= middle_price:
            middle_price = num
        else:
            return True
    return False

arr = [22, 25, 21, 18, 19.6, 17, 16, 20.5]
arr2 = [50, 51.25, 48.4, 49, 47.2, 48, 46.9]
arr3 = [5,2,8,4,3,7]

print(upward_trend(arr))
print(upward_trend(arr2))
print(upward_trend(arr3))
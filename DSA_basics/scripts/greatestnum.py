#Exercise
'''
Write three different implementations of a function that finds the greatest number within an array. 
Write one function that is O(N2), one that is O(N log N), and one that is O(N).
'''

# approach 1 : O(N^2)
def greatest_numberN2(arr):
    if len(arr) == 0:
        return -1
    if len(arr) == 1:
        return arr[0]
    for i in range(len(arr)):
        is_greatest = True
        for j in range(len(arr)):
            if arr[j] > arr[i]:
                is_greatest = False
        
        if is_greatest:
            return arr[i]

def greatest_number_nlogn(arr):
    if len(arr) == 0:
        return -1
    if len(arr) == 1:
        return arr[0]
    arr.sort()
    return arr[-1]

def greatest_number_n(arr):
    if len(arr) == 0:
        return -1
    if len(arr) == 1:
        return arr[0]
    max = arr[0]
    for i in range(1,len(arr)):
        if arr[i] > max:
            max = arr[i]
    return max

arr = [1,2,9,4,10,3]

print(greatest_numberN2(arr))
print(greatest_number_nlogn(arr.copy()))
print(arr)
print(greatest_number_n(arr))
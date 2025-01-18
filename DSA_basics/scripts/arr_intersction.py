def intersection_array(arr1, arr2):
    result = []
    for i in arr1:
        for j in arr2:
            if i == j:
                result.append(i)
    return result

arr1 = [3,1,4,2]
arr2 = [4,5,3,6]

def intersection_array_better(arr1, arr2):
    result = []
    for i in arr1:
        for j in arr2:
            if i==j:
                result.append(i)
                break
    return result
print(intersection_array(arr1,arr2))
print(intersection_array_better(arr1,arr2))

# time complexity O(n^2)
# the optimized one also has O(n^2) in the worst cases, but the best case is O(n) and on average between O(n) and O(n^2)
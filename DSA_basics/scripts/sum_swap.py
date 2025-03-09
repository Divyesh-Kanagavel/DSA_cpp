# problem : We want to write a function that accepts two arrays of integers. Our function needs to find one number from each array that can be swapped to cause the two array sums to be equal.

# solution : find the difference between sums of two arrays. divide the number by two. that will be the difference between numbers which are swapped in the two arrays
# one possible approach to find the two numbers is to use nested loops with time complexity O(n*m) and space complexity O(1)
# a faster approach is to use hash tables to store indices with time comeplxity O(n+m) but space complexity of O(n)


def sum_swap(arr1, arr2):
    hash_table = {}
    sum_1 = 0
    sum_2 = 0
    for i in range(len(arr1)):
        sum_1 += arr1[i]
        hash_table[arr1[i]] = i
    
    for i in range(len(arr2)):
        sum_2 += arr2[i]
    
    shift_amount = (sum_1 - sum_2) / 2

    for i in range(len(arr2)):
        if hash_table.get(arr2[i] + shift_amount):
            return [hash_table[arr2[i]+shift_amount], i]
    return []

arr1 = [5,3,2,9,1]
arr2 = [1,12,5]

print(sum_swap(arr1,arr2))



    


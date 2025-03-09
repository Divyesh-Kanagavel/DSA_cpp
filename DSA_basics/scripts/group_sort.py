# problem : Let’s say we have an array containing several different values and we want to reorder the data so that the same values are grouped together. 

# solution : use hash table to store the elements with its frequency in a hashmap. 
# then feed these elements into an array in an order. this solves the problem
# time complexity  :O(n) space complexity : O(n)

# other approach : sort the entire array, time complexity = O(nlogn), space complexity : O(logn)

def group_sort_v1(arr):
    return sorted(arr)

def group_sort_v2(arr):
    group_hash = {}
    new_arr = []
    for i in arr:
        if group_hash.get(i):
            group_hash[i] += 1
        else:
            group_hash[i] = 1
    
    for i in group_hash:
        for j in range(group_hash[i]):
            new_arr.append(i)
    
    return new_arr

    


# tests

arr = ['b','c','a','a','d','b','c','c','d']
print(group_sort_v1(arr))
print(group_sort_v2(arr))
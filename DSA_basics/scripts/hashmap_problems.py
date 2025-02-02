# find intersection of two arrays in O(N) time complexity.
def merge_arrays(arr1,arr2):
    hash = {}
    merged_arr = []
    for i in arr1:
        hash[i] = 1
    for i in arr2:
        if hash.get(i,0):
            merged_arr.append(i)
    return merged_arr

# return first duplicate element in a string

def first_duplicate(s):
    hash = {}
    for i in s:
        if hash.get(i,0):
            return i
        else:
            hash[i] = 1
    return None

# find missing letter in the string
def missing_letter(s):
    hash = {}
    for i in s:
        if not hash.get(i,0):
            hash[i] = 1
    for i in range(97,123):
        if not hash.get(chr(i),0):
            return chr(i)

# return first non-duplicated element in an array
def first_nonduplicate(array):
    hash = {}
    for i in array:
        if hash.get(i,0):
            hash[i] += 1
        else:
            hash[i] = 1
    
    for i in hash:
        if hash[i] == 1:
            return i
        





# test
arr1 = [1,3,5,7,9]
arr2 = [3,6,9]
print(merge_arrays(arr1,arr2))

s = "abac"
dup = first_duplicate(s)
if dup :
    print(dup)

s = "the quick brown box jumps over a lazy dog"
print(missing_letter(s))

s = "minimum"
print(first_nonduplicate(s))
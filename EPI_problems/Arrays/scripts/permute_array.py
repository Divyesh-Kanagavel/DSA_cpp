# Given an array A of n elements and a permutation P, apply P to A.
# brute force approach : create a new array of the same size. 
# copy contents from A in the order given by the permutation P.
# Time complexity : O(N), space complexity : O(N)
def permute_array_brute(arr, perm):
    new_arr = []
    for i in range(len(arr)):
        new_arr.append(arr[perm[i]])
    return new_arr
# solution with O(1) space complexity -> does not work , you atleast need an extra boolean array with space compexity O(logn)
def permute_array(arr,p):
    for i in range(len(arr)):
        if p[i] >= 0:
            val = arr[i]
            cur = i
            while p[cur] >= 0:
                next_idx = p[cur]
                arr[cur] = arr[next_idx]
                p[cur] = -1
                cur = next_idx
            arr[cur] = val



# test
if __name__ == "__main__":
    arr = [0,9,8,1,4,6]
    perm = [4,2,1,0,3,5]
    new_arr = permute_array_brute(arr,perm)
    print(new_arr)
    permute_array(arr, perm)
    print(arr)



# Write a program which takes as input a sorted atay A of integers and a positiveinteger m,
# and updates A so that if x appears z times in A it appears exactly min(2,m) times in A. The update
# to A should be performed in one pass, and no additional storage may be allocated.

def removetwoplus_dup(arr):
    if not arr:
        return 0
    write_index = 1
    num_reps = 0
    for i in range(1,len(arr)):
        if arr[write_index-1] != arr[i]:
            arr[write_index] = arr[i]
            write_index += 1
        elif arr[write_index-1] == arr[i] and num_reps < 1:
            arr[write_index] = arr[i]
            write_index += 1
            num_reps += 1
        else:
            num_reps = 0
    return write_index
# tests 
if __name__ == "__main__":
    arr = [0,1,1,1,2,3,3,4,5,5,5,6,6,7]
    write_index = removetwoplus_dup(arr)
    print(arr[:write_index])
    



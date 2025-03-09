'''
problem : 
You're writing a function that accepts an array of unsorted integers and returns the length of the longest consecutive sequence among them. The sequence is formed by integers that increase by 1
'''
# sort and then find longest consecutive sequence - time complexity - O(nlogn)
def find_consecutive_sequence_v1(arr):
    arr_sorted = sorted(arr)
    longest_sequence = 0
    current_sequence = 1

    for i in range(1,len(arr_sorted)):
        if arr_sorted[i] == arr_sorted[i-1] + 1:
            current_sequence += 1
        else:
            current_sequence = 1
        
        longest_sequence = max(longest_sequence, current_sequence)
    return longest_sequence

def find_consecutive_sequence_v2(arr):
    longest_sequence = 0
    seq_hash = {}
    for i in arr:
        seq_hash[i] = True

    for i in arr:
        if not seq_hash.get(i-1):
            current_sequence_length = 1
            current_number = i
            while seq_hash.get(current_number+1):
                current_number+=1
                current_sequence_length +=1
        
            longest_sequence = max(longest_sequence,current_sequence_length)

    return longest_sequence



arr = [10, 5, 12, 3, 55, 30, 4, 11, 2]
arr2 = [19, 13, 15, 12, 18, 14, 17, 11]
print(find_consecutive_sequence_v1(arr))
print(find_consecutive_sequence_v1(arr2))

print(find_consecutive_sequence_v2(arr))
print(find_consecutive_sequence_v2(arr2))
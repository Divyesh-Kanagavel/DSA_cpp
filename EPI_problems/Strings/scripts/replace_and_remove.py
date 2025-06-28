# Write a program which takes as input an array of characters, and removes each 'b' and replaces
# each'a'by two 'd's.

# trivial solutions:
# delete b at the location, shift all elements to left
# insert two ds inplace of a , shift all elements to right
# but O(N^2) time comeplexity
# or write the result to a new array -> O(n) space complexity
# better solution uses O(1) space and O(n) time complexity

# the idea is to first iterate through the array , deleting b by moving on the next element
# compute number of valid elements in the string.
# now allocate extra space for extra d's in place of a and work backwards deleting a when encountered and putting two d's in place

def replace_and_remove(s,size):
    write_idx = num_a = 0
    for i in range(size):
        if s[i]!='b':
            s[write_idx] = s[i]
            write_idx += 1
        if s[i] == 'a':
            num_a += 1
    
    cur_idx = write_idx - 1
    write_idx += num_a - 1
    final_size = write_idx + 1
    while cur_idx >= 0:
        if s[cur_idx] == 'a':
            s[write_idx - 1: write_idx + 1] = "dd"
            write_idx -= 2
        else:
            s[write_idx] = s[cur_idx]
            write_idx -= 1
        cur_idx -= 1
    return final_size

if __name__ == "__main__":
    s = ['a','a','b','c','b','c','a','b']
    size = 8
    replace_and_remove(s,size)
    print(s)
#  Write a program which merges two sorted arrays of integers, A and B. Specifically, the
# final result should be a sorted array of length tn + n, where n and m are t}r.e lengths of A arrd B,
# respectively. Use O(1) additional storage-assume the result is stored in A, which has sufficient
# space. These arrays are C-style arrays, i.e., contiguous preallocated blocks of memory.
# assumed that A and B are sorted and both of them have lowercase letters
# A has more size to store combined array
def merge_array(A, B, len_a, len_b):
    write_idx = len_a + len_b - 1
    index_a = len_a - 1
    index_b = len_b - 1
    while index_b >= 0:
        if index_a >= 0 and ord(A[index_a]) > ord(B[index_b]):
            A[write_idx] = A[index_a]
            index_a -= 1
        else:
            A[write_idx] = B[index_b]
            index_b -= 1
        write_idx -= 1


if __name__ == "__main__":
    A = ['a','b','c','','','','',''] # extra space to merge array and put it in A
    B = ['d','f','j','m','z']

    merge_array(A,B, 3,5)
    print(A)

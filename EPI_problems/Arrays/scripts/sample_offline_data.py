# Implement an algorithm that takes as input an array of distinct elements and a size, and returns
# a subset of the given size of the array elements. All subsets should be equally likely. Retum the
# result in input array itself.
# Naive approach : 
# Iterate through the input array and select elements with probability k/N

# random sampling  -> to build a random subset of size k, we build subset of size 
# k-1 and then sample the one remainign elements from the rest of the array.
import random
# O(k) time complexity and O(1) space complexity
def random_sampling(arr, k):
    for i in range(k):
        idx = random.randint(i, len(arr)-1)
        arr[idx], arr[i] = arr[i], arr[idx]

if __name__ == "__main__":
    A = [1,5,6,9,11]
    k = 3
    random_sampling(A, k)
    print(A[:k])

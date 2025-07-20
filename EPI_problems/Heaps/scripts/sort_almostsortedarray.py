# Write a Program which takes as input a very long sequence of numbers and prints the numbers in
# sorted order. Each number is at most k away from its correctly sorted position. (Such an array is
# sometimesreferredtoasbeingk-sorted.) Forexample,nonumberinthesequence(3, -1.,2,6,4,5,8>
# is more than 2 away from its final sorted position.

# brute force : sort the entire array -> O(nlogn)
# faster approach : each number is not more than k position away from correct position
# so, if we read in k numbers, the smallest number is within this sequence
# so, read k numbers, when a new number is read, pop the min element in the heap and add the incoming element
# O(nlogk) again and O(k) space complexity

import heapq
import itertools

def sort_almost_sortedarray(arr, k):
    min_heap = []
    result = []

    for x in itertools.islice(arr, k):
        heapq.heappush(min_heap, x)
    
    for x in arr[k+1:]:
        smallest = heapq.heappushpop(min_heap, x)
        result.append(smallest)
    
    while min_heap:
        smallest = heapq.heappop(min_heap)
        result.append(smallest)

    return result


if __name__ == "__main__":
    seq = [3, -1,2,6,4,5,8]
    sorted_arr = sort_almost_sortedarray(seq,2)
    print(sorted_arr)



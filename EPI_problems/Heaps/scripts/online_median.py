# Design an algorithm for computing the running median of a sequence.

# for scenarios where we need to deal with online stream of data, storing and computing is 
# expensive or infeasible. So we rely on heap to do the same. because it can store
# the maximum element or minimum of array at the first position itself

# approach:
# have two heaps : min_heap storing large elements with min of subarray at position 0
# max_heap : storing smaller subarray with max element at position 
# these two are enough to compute median. introduction of new element should be disturbing only these entities

# when a new element arrives, push it in min_heap, pop the smallest element and put it in max_heap
# always keep both heaps balanced and if there is a need to have imbalance, keep the size of min_heap 1 greater than max_heap
# median : min_heap[0] + max_heap / 2 if both lengths are same, else min_heap[0]
# time complexity : O(logn)
import heapq

def compute_median_online(arr):
    min_heap = [] # store larger sub-array
    max_heap = [] # store smaller sub-array
    result = []

    for x in arr:
        heapq.heappush(max_heap, -heapq.heappushpop(min_heap, x))

        if len(max_heap) > len(min_heap):
            heapq.heappush(min_heap, -heapq.heappop(max_heap))
        result.append(0.5 * (min_heap[0] + -max_heap[0]) if len(min_heap) == len(max_heap)
                      else min_heap[0])
    return result

if __name__ == "__main__":
    sequence = [3,4,1,9,7,1,0,8]
    print(compute_median_online(sequence))
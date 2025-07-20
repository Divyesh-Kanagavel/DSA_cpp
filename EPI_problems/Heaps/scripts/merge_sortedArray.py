# Write a program that takes as input a set of sorted sequences and computes the union of these
# sequences as a sorted sequence. For example, if the input is <3,5,7>, (0,5), and <0,6,28>, then the
# output is (0, 0, 3, 5, 6, 6,7, 28).
# brute force approach -> concat the arrays into a large array
# sort the array -> O(nlogn)
# approach 2 : merge using heap. maintain a heap to choose smallest element and push it to output
# if the number of input sequences is k, there are k elements in the heap
# so , insertion takes O(logk). we insert n elements -> so O(nlogk) < O(nlogn)
def merge_sorted_array(sorted_array):
    min_heaps = []
    # list of iterators
    sorted_iters = [iter(x) for x in sorted_array]

    for i, it in enumerate(sorted_iters):
        first_element = next(it, None)
        if first_element is not None:
            heapq.heappush(min_heaps,(first_element, i))
    
    result = []
    while min_heaps:
        smallest_element, smallest_array_i = heapq.heappop(min_heaps)
        smallest_array_iter = sorted_iters[smallest_array_i]
        result.append(smallest_element)
        next_element = next(smallest_array_iter, None)
        if next_element is not None:
            heapq.heappush(min_heaps, (next_element, smallest_array_i))
    return result




import heapq # python library to work with heaps [by default min-heap]
if __name__ == "__main__":
    seqs = [[3,5,7],[0,6], [0,6,28]]
    sorted_array = merge_sorted_array(seqs)
    print(sorted_array)


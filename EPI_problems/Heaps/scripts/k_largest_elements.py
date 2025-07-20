# Given a max-heap, represented as an array A, design an algorithm that computes the k
# largest elements stored in the max-heap. You cannot modify the heap

# approaches : 
# extract k largest elements from heap one by one -> O(klogn) , but it modifies the heap . So not useful
# find the kth largest element and choose elements before that -> O(n) and modifies the heap too
# the max element is at root itself. then you go through the children, picking the bigger ones. to choose the bigger ones among children as you go down,use a max heap for that as well
# time complexity : O(klogk)
import heapq
import itertools

def find_k_largest(A, k):
    if k <= 0:
        return []
    result = []
    candidate_heap = []
    candidate_heap.append((A[0], 0))
    for _ in range(k):
        candidate_idx = candidate_heap[0][1] # pick the largest
        result.append(-heapq.heappop(candidate_heap)[0])
        left_idx = 2 * candidate_idx + 1
        if left_idx < len(A):
            heapq.heappush(candidate_heap, (A[left_idx], left_idx))
        right_idx = 2 * candidate_idx + 2
        if right_idx < len(A):
            heapq.heappush(candidate_heap, (A[right_idx], right_idx))
    return result


if __name__ == "__main__":
    seq = [3,4,1,9,0,5,7]
    A = []
    for x in seq:
        heapq.heappush(A, -x)

    k_largest = find_k_largest(A, 4)
    print(k_largest)


    
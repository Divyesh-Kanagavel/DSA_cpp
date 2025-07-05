# Write a Program that takes two cycle-free singly linked lists, and determines if there exists a node
# that is corunon to both lists.
from linked_list import *

# idea
# Both the lists have to converge at a node if there is a common node. and after that both reach the same tail
# So, if both have same tail, it means they have overlapping nodes
# to find the first overlapping node, find the diff between both the nodes
# advance the longer list by diff between both nodes length
# then advance both till common node is reached

def common_overlapping_node(L1, L2):
    def find_length(L1):
        length = 0

        while L1!=None:
            length += 1
            L1 = L1.next
        return length
    
    L1_len, L2_len = find_length(L1), find_length(L2)
    if L1_len > L2_len:
        L1, L2 = L2, L1  # keeping L2 as bigger list for convenience
    # advance the longer list by diff of lengths between two lists
    for _ in range(abs(L1_len - L2_len)):
        L2 = L2.next
    while L1 and L2 and L1 is not L2:
        L1, L2 = L1.next, L2.next
    return L1 # returns None if there is no overlap

if __name__ == "__main__":
    A = ListNode(1)
    B = ListNode(2)
    C = ListNode(3)
    D = ListNode(4)
    E = ListNode(5)
    F = ListNode(6)
    G = ListNode(7)
    # first list
    A.next = B
    B.next = C
    C.next = F
    F.next = G
    # second list
    D.next = E
    E.next = F
    first_overlap = common_overlapping_node(A,D)
    print(first_overlap, first_overlap.data)





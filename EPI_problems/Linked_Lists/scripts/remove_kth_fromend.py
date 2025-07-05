# Given a singly linked list and an integer k, write a program to remove the kth last element from the
# list.

# brute force approach -> pass through the list to find the size
# then to delete kth item from end means deleting (l-k)th item from beginning
# otherwise, we could maintain two pointers , one at node k and one at the beginning
# we traverse till first pointer reaches the end
from linked_list import *
def reach_kth_last(L, k):
    dummy_head = ListNode(0,L)
    first = dummy_head.next
    for _ in range(k):
        first = first.next
    second = dummy_head
    while first:
        first, second = first.next, second.next
    second.next = second.next.next
    return dummy_head.next

if __name__ == "__main__":
    A = ListNode(3)
    B = ListNode(5)
    C = ListNode(9)
    D = ListNode(1)
    E = ListNode(6)
    A.next = B
    B.next = C
    C.next = D
    D.next = E

    lastk_deleted = reach_kth_last(A, 4)
    print_list(lastk_deleted)

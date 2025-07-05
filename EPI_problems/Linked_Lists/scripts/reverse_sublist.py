# Write a program which takes a singly linked list L and two integers s and / as arguments, and
# reverses the order of the nodes from the sth node to /th node, inclusive. The numbering begins at
# 1., i.e., the head node is the first node. Do not allocate additional nodes.
from linked_list import *
def reverse_sublist(llist, s, f):
    dummy_head = sublist_head = ListNode(0, llist)
    for _ in range(1, s):
        sublist_head = sublist_head.next
    sublist_iter = sublist_head.next
    for _ in range(f-s):
        temp = sublist_iter.next
        sublist_iter.next, temp.next, sublist_head.next = temp.next, sublist_head.next, temp
    return dummy_head.next

if __name__ == "__main__":
    L = create_list([2,5,8,9,11]) # sorted list 1
    print_list(L)
    reversed_sub = reverse_sublist(L, 2, 5)
    print_list(reversed_sub)

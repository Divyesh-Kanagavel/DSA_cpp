# Write a program that computes the even-odd merge.
from linked_list import *
def even_odd_merge(L):
    if not L:
        return L
    
    even_dummy_head, odd_dummy_head = ListNode(0), ListNode(0)
    tails, turn = [even_dummy_head, odd_dummy_head], 0
    while L:
        tails[turn].next = L
        tails[turn], L = tails[turn].next, L.next
        turn ^= 1
    tails[1].next = None
    tails[0].next = odd_dummy_head.next
    return even_dummy_head.next

if __name__ == "__main__":
    L = create_list([2,3,4,5,6,7,8])
    print_list(L)
    even_odd_L = even_odd_merge(L)
    print_list(even_odd_L)

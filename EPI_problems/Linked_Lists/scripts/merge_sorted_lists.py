# Write a program that takes two lists, assumed to be sorted, and returns their merge. The only field
# your program can change in a node is its next field.
from linked_list import *
def merge_two_sorted_lists(L1, L2):
    dummy_head = tail = ListNode() # place holder for result
    while L1 and L2:
        if L1.data < L2.data:
            tail.next, L1 = L1, L1.next
        else:
            tail.next, L2 = L2, L2.next
        tail = tail.next
    tail.next = L1 or L2 # append the remaining items
    return dummy_head.next

if __name__ == "__main__":
    L1 = create_list([2,5,9,11]) # sorted list 1
    L2 = create_list([3,4,7,12,14])
    print("L1 = ", end = "")
    print_list(L1)
    print("L2 = ", end = "")
    print_list(L2)
    M = merge_two_sorted_lists(L1, L2)
    print("merged list = ", end= "")
    print_list(M)


    

    

# merge two doubly linked lists

from dll import *

def merge_dlls(DL1, DL2):
    dummy_head = tail = DLLNode()
    while DL1 and DL2:
        prev = tail
        if DL1.data < DL2.data:
            tail.next, DL1 = DL1, DL1.next
        else:
            tail.next, DL2 = DL2, DL2.next
        tail = tail.next
        tail.prev = prev
    tail.next = DL1 or DL2
    tail.next.prev = tail
    return dummy_head.next


if __name__ == "__main__":
    L1 = create_dll([2,5,9,11]) # sorted list 1
    L2 = create_dll([3,4,7,12,14])
    print("L1 = ", end = "")
    print_dll(L1)
    print("L2 = ", end = "")
    print_dll(L2)
    M = merge_dlls(L1, L2)
    print("merged list = ", end= "")
    print_dll(M)




# Write a program that takes the head of a singly linked list and retums null if there does not exist a
# cycle, and the node at the start of the cycle, if a cycle is present, (You do not know the length of the
# list in advance.)

# Approaches:
# 1. Hash map : store the visited nodes in a hash map and if a node is hash map is encountered , return cycle exists -> O(N) space complexity
# 2. Use a double for loop to traverse node by node in outer for loop and in the inner loop, traverse till index of outer loop and if you find a duplicate, cycle exists 
# 3. Use Floyd cycle finding algorithm -> tortoise and hare algorithm [both with and without finding cycle length]
from linked_list import *
def has_cycle(head):
    def len_cycle(end):
        start, step = end, 0
        while True:
            start = start.next
            step += 1
            if start is end:
                return step
    fast = slow = head
    while fast and fast.next and fast.next.next:
        slow, fast = slow.next, fast.next.next
        if slow is fast: # cycle exists
            cycle_iter = head
            for _ in range(len_cycle(slow)):
                cycle_iter = cycle_iter.next
            iter = head
            while iter is not cycle_iter:
                iter = iter.next
                cycle_iter = cycle_iter.next
            return iter
    return None

def has_cycle_succinct(head):
    fast = slow = head
    while fast and fast.next and fast.next.next:
        slow , fast = slow.next, fast.next.next
        if slow is fast: # existence of cycle
            slow = head
            while slow is not fast:
                slow = slow.next
                fast = fast.next
            return slow
    return None



if __name__ == "__main__":
    A, B, C, D, E, F = ListNode(0), ListNode(1), ListNode(2),ListNode(3), ListNode(4), ListNode(5)
    A.next = B
    B.next = C
    C.next = D
    D.next = E
    E.next = F
    F.next = C

    start_node = has_cycle_succinct(A)
    if start_node:
        print(start_node, start_node.data)
    else:
        print("No cycle")


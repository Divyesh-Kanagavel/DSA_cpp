# Write a program that tests whether a singly linked list is palindromic.

from linked_list import *

def reverse_linked_list(L):
    prev = None
    current = L
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    L = prev 
    return L

def is_palindrome(L):
    slow = fast = L
    while fast and fast.next:
        fast , slow = fast.next.next, slow.next
    first_half_iter , second_half_iter = L, reverse_linked_list(slow)
    while first_half_iter and second_half_iter:
        if first_half_iter.data != second_half_iter.data:
            return False
        second_half_iter, first_half_iter = second_half_iter.next, first_half_iter.next
    return True

if __name__ == "__main__":
    L = create_list([1,2,2,1])
    print(is_palindrome(L))
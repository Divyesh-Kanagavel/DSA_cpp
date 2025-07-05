# a linked list prototype which can be reused in other files in this chapter
class ListNode:
    def __init__(self, data = 0, next_node= None):
        self.data = data
        self.next = next_node

def create_list(arr):
    dummy_head = root = ListNode(arr[0])
    for i in range(1,len(arr)):
        root.next = ListNode(arr[i])
        root = root.next
    return dummy_head

def print_list(root):
    while root!=None:
        print(root.data, end=",") if root.next != None else print(root.data)
        root = root.next




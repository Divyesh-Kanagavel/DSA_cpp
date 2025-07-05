# doubly linked list helper

# a linked list prototype which can be reused in other files in this chapter
class DLLNode:
    def __init__(self, data = 0, prev_node = None,next_node= None):
        self.data = data
        self.next = next_node
        self.prev = prev_node

def create_dll(arr):
    dummy_head = root = DLLNode(arr[0])
    for i in range(1,len(arr)):
        temp = root
        root.next = DLLNode(arr[i])
        root = root.next
        root.prev = temp
    return dummy_head

def print_dll(root):
    while root.next!=None:
        print(root.data, end=",")
        root = root.next
    print(root.data)
    print("printing backwards using prev pointer for validation")
    tail = root
    while tail!=None:
        print(tail.data, end=",") if tail.prev != None else print(tail.data)
        tail = tail.prev

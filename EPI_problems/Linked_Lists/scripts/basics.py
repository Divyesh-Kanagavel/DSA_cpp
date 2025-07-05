# basic linked list operations - search, insert, delete demo

from linked_list import ListNode

def search_list(L, key):
    while L and L.data != key:
        L = L.next
    # if key not present, returns NULL
    return L

def insert_after(node,new_node):
    new_node.next = node.next
    node.next = new_node
# delete the node past this one
def delete_node(node):
    # assume node is not tail
    node.next = node.next.next

def print_list(root):
    while root!=None:
        print(root.data)
        root = root.next

if __name__ == "__main__":
    a = ListNode(3)
    b = ListNode(4,a)
    c = ListNode(5,b)
    d = ListNode(6,c)
    new_node = ListNode(9)
    insert_after(a,new_node)
    print_list(d)
    delete_node(b)
    print_list(d)



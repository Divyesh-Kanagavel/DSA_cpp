# Node adapted to work with doubly linked list
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        self.prev = None

class DoubleLinkedList:
    def __init__(self,head = None, tail = None):
        self.head = head
        self.tail = tail
    
    def __repr__(self):
        nodes = []
        current = self.head
        while current:
            nodes.append(current.data)
            current = current.next
        return str(nodes)
    
    def read(self, index):
        current_node = self.head
        current_index = 0
        while current_index < index:
            current_index += 1
            current_node = current_node.next
            if current_node is None:
                return None
        return current_node.data
    
    def search_forward(self, value):
        current_node = self.head
        current_index = 0
        while current_node is not None:
            if current_node.data == value:
                return current_index
            current_node = current_node.next
            current_index += 1
        return None
    
    def search_backward(self, value):
        current_node = self.tail
        current_index = -1
        while current_node is not None:
            if current_node.data == value:
                return current_index
            current_node = current_node.prev
            current_index -= 1
        return None 
    # additional functions specific to doubly linked list
    def insert_front(self,value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            new_node.prev = None
            new_node.next = None
        else:
            self.head.prev = new_node
            new_node.next = self.head
            self.head = new_node
    
    def insert_back(self,value):
        new_node = Node(value)
        if self.tail is None:
            self.head = new_node
            self.tail = new_node
            new_node.prev = None
            new_node.next = None
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node

    
        

        


dll = DoubleLinkedList()
node_1 = Node(4)

print(dll)

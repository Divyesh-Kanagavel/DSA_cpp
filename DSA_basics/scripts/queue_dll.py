class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        self.prev = None
    
class DoublyLinkedList:
    def __init__(self, head = None, tail = None):
        self.head = head
        self.tail = tail
    
    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
    
    def delete_from_front(self):
        if self.head is None:
            return None
        else:
            data = self.head.data
            self.head = self.head.next
            self.head.prev = None
            return data


# implementatin of queue using doubly linked list -> O(1) time complexity for 
# deletion from front and insertion at the end
class Queue:
    def __init__(self):
        self.dll = DoublyLinkedList()
    def enqueue(self, value):
        self.dll.insert_at_end(value)
    def dequeue(self):
        return self.dll.delete_from_front()
    def read(self):
        if self.dll.head is None:
            return None
        else:
            return self.dll.head.data
    def __repr__(self):
        nodes = []
        current = self.dll.head
        while current:
            nodes.append(current.data)
            current = current.next
        return str(nodes)

# test
queue = Queue()
queue.enqueue(1)
queue.enqueue(9)
print(queue)
print(queue.dequeue())
print(queue)
queue.enqueue(8)
print(queue)
print(queue.read())
print(queue.dequeue())
print(queue)
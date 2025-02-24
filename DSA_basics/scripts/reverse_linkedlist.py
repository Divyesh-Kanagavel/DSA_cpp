class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
    
class LinkedList:
    def __init__(self, first_node):
        self.head = first_node
    
    def __str__(self):
        current_node = self.head
        values = []
        while current_node is not None:
            values.append(current_node.data)
            current_node = current_node.next
        return str(values)
    
    # read method - O(N)
    def read(self, index):
        current_node = self.head
        current_index = 0
        while current_index < index:
            current_node = current_node.next
            current_index += 1
            if current_node is None:
                return None
        return current_node.data
    
    # search method - O(N)
    def search(self, value):
        current_node = self.head
        current_index = 0

        while current_node is not None:
            if current_node.data == value:
                return current_index
            current_node = current_node.next
            current_index +=1
        return None
    
    #insert method - O(1) at beginning and O(N) at the end
    def insert(self, value, index):
        new_node = Node(value)
        if index == 0:
            new_node.next = self.head
            self.head = new_node
        else:
            current_node = self.head
            current_index = 0
            while current_index < index - 1:
                current_node = current_node.next
                current_index += 1
            
            if current_node is None:
                print("index out of range!")
                return
            new_node.next = current_node.next
            current_node.next = new_node
        
        #deletion of node
    def delete(self, index):
            if index == 0:
                self.head = self.head.next
            else:
                current_node = self.head
                current_index = 0
                while current_index < index - 1:
                    current_node = current_node.next
                    current_index += 1
                if current_node.next is None:
                    print("index out of range!")
                    return
                    
                current_node.next = current_node.next.next
    
    def reverse_linked_list(self):
        if self.head is None:
            return None
        else:
            current_node = self.head
            prev_node = None
            while current_node:
                next_node = current_node.next
                current_node.next = prev_node
                prev_node = current_node
                current_node = next_node
            self.head = prev_node

# test
node1 = Node(1)
node2 = Node(5)
node3 = Node(6)
node1.next = node2
node2.next = node3

l_list = LinkedList(node1)
print(l_list)

l_list.reverse_linked_list()
print(l_list)



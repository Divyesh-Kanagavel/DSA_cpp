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

            

    

#construction of nodes
node_1 = Node(1)
node_2 = Node(2)
node_3 = Node(3)

node_1.next = node_2
node_2.next = node_3

# read
l_list = LinkedList(node_1)
print(l_list.read(5))
#search
print(l_list.search(4))
#insert
l_list.insert(5,3)
print(l_list)
#delete
l_list.delete(4)
print(l_list)





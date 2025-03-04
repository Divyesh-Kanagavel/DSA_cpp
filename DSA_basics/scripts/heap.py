# heap data structure implemented as arrays

class Heap:
    def __init__(self):
        self.data = []
    # contains the minimum or maximum value depending on min-heap or max-heap
    def first_node(self):
        return self.data[0]
    # returns the last node i.e in the bottom most level, the right most node
    def last_node(self):
        return self.data[-1]
    
    def left_child_index(self, index):
        return (2 * index + 1)
    
    def right_child_index(self, index):
        return (2 * index + 2)
    
    def parent_index(self, index):
        return (index - 1)//2
    
    # insertion of value into the heap
    # insert the value at the end after last node
    # trickle the value up to correct position i.e the point where its children are smaller than it
    def insert(self, value):
        self.data.append(value)
        new_index = len(self.data)-1
        while new_index > 0 and self.data[new_index] > self.data[self.parent_index(new_index)]:
            self.data[new_index], self.data[self.parent_index(new_index)] = self.data[self.parent_index(new_index)], self.data[new_index]
            new_index = self.parent_index(new_index)
    
    # deletion of value from the heap
    # replace the root value with last value in the heap
    # trickle it down into the correct position
    def delete(self):
        if len(self.data) == 1:
            self.data.pop()
            return
        self.data[0] = self.data.pop()
        
        new_index = 0
        while new_index < len(self.data) and self.has_greater_child(new_index):
            larger_child_index = self.calculate_larger_child(new_index)
            self.data[new_index], self.data[larger_child_index] = \
                self.data[larger_child_index], self.data[new_index]
            new_index = larger_child_index
    
    def has_greater_child(self, index):
        left_child_greater = False
        if self.left_child_index(index) <  len(self.data):
            left_child_greater = self.left_child_index(index) and self.data[self.left_child_index(index)] > self.data[index]

        if self.right_child_index(index) < len(self.data):
            right_child_greater = self.data[self.right_child_index(index)] > self.data[index]
            return left_child_greater or right_child_greater
        else:
            return left_child_greater
   
    def calculate_larger_child(self, index):
        if self.right_child_index(index) >= len(self.data):
            return self.left_child_index(index)
        
        if self.data[self.left_child_index(index)] > self.data[self.right_child_index(index)]:
            return self.left_child_index(index)
        else:
            return self.right_child_index(index)


# tests

heap = Heap()
heap.insert(55)
heap.insert(22)
heap.insert(34)
heap.insert(10)
heap.insert(2)
heap.insert(99)
heap.insert(68)

print(heap.data)

# deletion
heap.delete()
print(heap.data)
heap.delete()
print(heap.data)
heap.delete()
print(heap.data)
heap.delete()
print(heap.data)
heap.delete()
print(heap.data)
heap.delete()
print(heap.data)
heap.delete()
print(heap.data)
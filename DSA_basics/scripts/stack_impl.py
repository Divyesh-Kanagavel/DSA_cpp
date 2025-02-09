# abstract data types
'''
Data structures like arrays are concrete data structures whose implementations 
are available in most programming languages. 
Data structures like stacks are abstract data types(ADTs) which are defined by 
theoretical rules like LIFO and under the hood, they can be implemented using 
concrete data structures like arrays or linked lists.
Stacks are used to store temporary data that could be discarded after use
'''

class stack:
    def __init__(self):
        self.data_ = []
    def push(self, value):
        self.data_.append(value)
    def pop(self):
        self.data_.pop()
    def top(self):
        return self.data_[-1]

# test
s = stack()
s.push(1)
s.push(5)
s.push(9)
s.pop()
s.top()


    

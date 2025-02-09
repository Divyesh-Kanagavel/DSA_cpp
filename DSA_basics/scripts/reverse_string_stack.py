
class Stack:
    def __init__(self):
        self.data = []
    
    def push(self, value):
        self.data.append(value)
    
    def pop(self):
        return self.data.pop()
    
    def read(self):
        return self.data[-1]

def reverse_string(string):
    s = Stack()
    for char in string:
        s.push(char)
    reversed_string = ""
    while s.data:
        reversed_string += s.pop()
    
    return reversed_string

s = "abcde"
print(reverse_string(s))
    

# Queue is a FIFO data structure - First in First Out
# Add an element to the end called back and pop from the front
# read the front only

class Queue:
    def __init__(self):
        self.data_ = []
    
    def enqueue(self, value):
        self.data_.append(value)
    
    def dequeue(self):
        self.data_.pop(0)
    
    def read(self):
        return self.data_[0]


queue = Queue()
queue.enqueue(1)
queue.enqueue(7)
queue.enqueue(8)
queue.dequeue()
print(queue.read())
print(queue.data_)


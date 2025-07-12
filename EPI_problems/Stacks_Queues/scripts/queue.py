# queue class demo
import collections
class Queue:
    def __init__(self):
        self._data = collections.deque()
    def enqueue(self, x):
        self._data.append(x)
    def dequeue(self):
        self._data.popleft() # remove from the front
    
    def max(self):
        return max(self._data)
    
if __name__ == "__main__":
    queue = Queue()
    queue.enqueue(3)
    queue.enqueue(6)
    queue.dequeue()
    queue.enqueue(0)
    queue.dequeue()
    print(queue._data)


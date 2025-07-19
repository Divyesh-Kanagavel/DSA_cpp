# How would you implement a queue given a library implementing stacks?

class Queue_S:
    def __init__(self):
        self._enq , self._deq = [], [] # two stacks
    def enqueue(self, x):
        self._enq.append(x) # enqueue to first stack
    def dequeue(self):
        if not self._deq:
            while self._enq:
                self._deq.append(self._enq.pop())
        if not self._deq:
            raise IndexError("empty queue")
        return self._deq.pop()
    
    def print(self):
        for i in self._deq[::-1]:
            print(i)
        for i in self._enq:
            print(i)
    
    
    
if __name__ == "__main__":
    queue = Queue_S()
    queue.enqueue(4)
    queue.enqueue(9)
    queue.enqueue(10)
    queue.dequeue()
    queue.enqueue(11)
    queue.dequeue()
    queue.print()


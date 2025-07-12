# Implement a queue API using an array for storing elements. Your API should include a constructor
# functioru which takes as argument the initial capacity of the queue, enqueue and dequeue functions,
# and a function which retums the number of elements store

class CircularQueue:
    Q_SCALE_FACTOR = 2
    def __init__(self, capacity):
        self._entries = [None] * capacity
        self._head = self._tail = 0
        self._num_elems = 0

    def enqueue(self, x):
        if self._num_elems == len(self._entries):
            self._entries = (
                self._entries[self._head:] + self._entries[:self._head]
            )
            self._head, self._tail = 0, self._num_elems
            self._entries += [None] * (len(self._entries) * self.Q_SCALE_FACTOR - len(self._entries))
        self._entries[self._tail] = x
        self._tail = (self._tail + 1) % len(self._entries)
        self._num_elems += 1

    def dequeue(self):
        if self._num_elems == 0:
            raise IndexError("empty queue")
        self._num_elems -= 1
        ret = self._entries[self._head]
        self._head = (self._head + 1) % len(self._entries)
        return ret

    def num_elements(self):
        return self._num_elems


if __name__ == "__main__":
    cq = CircularQueue(5)
    cq.enqueue(2)
    print(cq._entries, cq._head, cq._tail)
    cq.enqueue(3)
    print(cq._entries, cq._head, cq._tail)
    cq.enqueue(6)
    print(cq._entries, cq._head, cq._tail)
    cq.dequeue()
    print(cq._entries, cq._head, cq._tail)
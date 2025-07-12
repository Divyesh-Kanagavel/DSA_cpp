# Design a stack that includes a max operation, in addition to push and pop. The max method should
# return the maximum value stored in the stack.

# while pushing, push the element and update max if pushed element is greater than max
# while popping, it is not straightforward
# have a cache, which stores max till that entry's index. this way , there is no need to compute max from scratch during pop
# O(1) time complexity and O(N) time complexity
import collections
class Stack:
    ElementwithcachedMax = collections.namedtuple("ElementwithcachedMax", 
                                                  ('element','max'))
    
    def __init__(self):
        self._elementswithcachedMax = []
    
    def is_empty(self):
        return len(self._elementswithcachedMax) == 0
    
    def max(self):
        return self._elementswithcachedMax[-1].max
    
    def push(self, x):
        self._elementswithcachedMax.append(
            self.ElementwithcachedMax(x, x if self.is_empty() else
                                 max(x, self.max()))
        )

    def pop(self):
        if self.is_empty():
            raise IndexError("pop() : empty stack")
        return self._elementswithcachedMax.pop().element
    
    def print(self):
        for i in self._elementswithcachedMax:
            print(i.element, i.max)

# if we want to further save on space,we could try storing only the max value
# along with the count of max to handle duplicates

class StackwithMax:
    class MaxwithCount:
        def __init__(self, max, count):
            self.max = max
            self.count = count
    def __init__(self):
        self._element = []
        self._cachedmaxwithcount = []
    
    def is_empty(self):
        return len(self._element) == 0
    
    def max(self):
        if self.is_empty():
            raise IndexError("max() : empty stack")
        return self._cachedmaxwithcount[-1].max
    
    def pop(self):
        if self.is_empty():
            raise IndexError("pop() : empty stack")
        pop_element = self._element.pop()
        current_max = self._cachedmaxwithcount[-1].max
        if pop_element == current_max:
            self._cachedmaxwithcount[-1].count -= 1
            if self._cachedmaxwithcount[-1].count == 0:
                self._cachedmaxwithcount.pop()
        return pop_element
    
    def push(self, x):
        self._element.append(x)
        if len(self._cachedmaxwithcount) == 0:
            self._cachedmaxwithcount.append(self.MaxwithCount(x, 1))
        else:
            current_max = self._cachedmaxwithcount[-1].max
            if x == current_max:
                self._cachedmaxwithcount[-1].count += 1
            if x > current_max:
                self._cachedmaxwithcount.append(self.MaxwithCount(x, 1))


    

    

    

if __name__ == "__main__":
    stack = StackwithMax()
    stack.push(3)
    stack.push(9)
    print(stack.max())
    print(stack._element)
    stack.push(12)
    print(stack.max())
    print(stack._element)
    stack.pop()
    print(stack.max())
    print(stack._element)
    stack.pop()
    print(stack._element)
    print(stack.max())


    
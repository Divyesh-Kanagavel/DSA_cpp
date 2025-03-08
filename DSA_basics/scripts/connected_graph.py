
from collections import deque
class Vertex:
    def __init__(self, value):
        self.value = value
        self.neighbours = set()
    
    def add_adjacent_vertices(self, vertex, is_undirected=False):
        if is_undirected:
            if vertex in self.neighbours:
                return
            self.neighbours.add(vertex)
            vertex.add_adjacent_vertices(self,is_undirected)
        else:
            self.neighbours.add(vertex)
    
    def __str__(self):
        return str("value = " + self.value + ", neighbours are : " + str([neighbour.value for neighbour in self.neighbours]))
    
def dfs_traversal(vertex, visited = {}):
    visited[vertex.value] = True
    print(vertex.value)
    for neighbour in vertex.neighbours:
        if neighbour.value not in visited:
            dfs_traversal(neighbour, visited)

def bfs_traversal(vertex):
    queue = deque()
    visited_vertices = {}
    visited_vertices[vertex.value] = True
    queue.append(vertex)
    while queue:
        current_vertex = queue.popleft()
        print(current_vertex.value)
        for neighbour in current_vertex.neighbours:
            if neighbour.value not in visited_vertices:
                visited_vertices[neighbour.value] = True
                queue.append(neighbour)







alice = Vertex("Alice")
bob = Vertex("Bob")
charlie = Vertex("Charlie")

alice.add_adjacent_vertices(bob)
alice.add_adjacent_vertices(charlie)
bob.add_adjacent_vertices(charlie)

print(alice)
print(bob)
print(charlie)
print("dfs traversal:")
dfs_traversal(alice)
print("bfs traversal:")
bfs_traversal(alice)



            
        


        


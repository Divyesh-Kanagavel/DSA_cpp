# search for a vertex through bfs


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

def bfs_traversal(vertex, value):
    if vertex.value == value:
        return True
    queue = deque()
    visited_vertices = {}
    visited_vertices[vertex.value] = True
    queue.append(vertex)
    while queue:
        current_vertex = queue.popleft()
        if current_vertex.value == value:
            return True
        for neighbour in current_vertex.neighbours:
            if neighbour.value not in visited_vertices:
                visited_vertices[neighbour.value] = True
                queue.append(neighbour)
    return False

def find_shortest_path_unweighted(start_vertex, end_vertex):
    queue = deque()
    visited_vertices = {}
    previous_stopover_vertex = {}
    visited_vertices[start_vertex.value] = True
    queue.append(start_vertex)
    while queue:
        current_vertex = queue.popleft()
        for neighbour in current_vertex.neighbours:
            if neighbour.value not in visited_vertices:
                visited_vertices[neighbour.value] = True
                previous_stopover_vertex[neighbour.value] = current_vertex.value
                queue.append(neighbour)

    shortest_path = []
    current_vertex = end_vertex

    while current_vertex.value != start_vertex.value:
        shortest_path.append(current_vertex.value)
        current_vertex.value = previous_stopover_vertex[current_vertex.value]
    shortest_path.append(start_vertex.value)
    shortest_path.reverse()
    return shortest_path


#tests

alice = Vertex("Alice")
bob = Vertex("Bob")
charlie = Vertex("Charlie")
darwin = Vertex("Darwin")
erwin = Vertex("Erwin")

alice.add_adjacent_vertices(bob)
alice.add_adjacent_vertices(erwin)
alice.add_adjacent_vertices(charlie)
bob.add_adjacent_vertices(charlie)
bob.add_adjacent_vertices(darwin)
darwin.add_adjacent_vertices(charlie)

print(bfs_traversal(alice, "Fred"))

print(find_shortest_path_unweighted(alice, darwin))




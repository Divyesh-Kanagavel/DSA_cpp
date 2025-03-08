# implementation of Dijkstra's algorithm to solve for getting from city A 
# to city B with least amount of costs [cost -> weights, cities -> vertices]

class WeightedVertex:
    def __init__(self,value):
        self.value = value
        self.adjacent_vertices = {}
    
    def add_adjacent_vertices(self, vertex, weight):
        self.adjacent_vertices[vertex] = weight

class City:
    def __init__(self,name):
        self.name = name 
        self.routes = {}
    
    def add_route(self, city, price):
        self.routes[city] = price

chennai = City("Chennai")
delhi = City("Delhi")
mumbai = City("Mumbai")
bangalore = City("Bangalore")
hyderabad = City("Hyderabad")

chennai.add_route(bangalore,100)
chennai.add_route(mumbai, 160)
delhi.add_route(bangalore, 150)
delhi.add_route(mumbai, 60)
mumbai.add_route(bangalore, 70)
bangalore.add_route(delhi, 140)
bangalore.add_route(hyderabad,80)

def dijkstra_shortest_path(start_city, end_city):
    cheapest_price_table = {} # hashmap to hold cheapest prices from starting city for all cities
    cheapest_previous_stopover_city_table = {} # hashmap to store previous city for every city 

    visited_cities = {}
    unvisited_cities = set() # can be implemented using priority queue
    cheapest_price_table[start_city.name] = 0
    current_city = start_city

    while current_city:
        visited_cities[current_city.name] = True # set visited to True
        unvisited_cities.discard(current_city) # remove from unvisited cities if present

        for adjacent_city, price in current_city.routes.items():
            if adjacent_city.name not in visited_cities:
                unvisited_cities.add(adjacent_city)
            price_through_current_city = cheapest_price_table[current_city.name] + price
            if adjacent_city.name not in cheapest_price_table or price_through_current_city < cheapest_price_table[adjacent_city.name]:
                cheapest_price_table[adjacent_city.name] = price_through_current_city
                cheapest_previous_stopover_city_table[adjacent_city.name] = current_city.name

        current_city = list(unvisited_cities)[0] if unvisited_cities else None
        for city in unvisited_cities:
            if cheapest_price_table[city.name] < cheapest_price_table[current_city.name]:
                current_city = city
    # find the shortest path from starting point going in reverse  
    shortest_path = []
    price = 0
    current_city_name = end_city.name
    while current_city_name != start_city.name:
        shortest_path.append(current_city_name)
        current_city_name = cheapest_previous_stopover_city_table[current_city_name]

    
    shortest_path.append(start_city.name)

    shortest_path.reverse()
    return shortest_path, cheapest_price_table[end_city.name]

print(dijkstra_shortest_path(delhi, bangalore))
    
        



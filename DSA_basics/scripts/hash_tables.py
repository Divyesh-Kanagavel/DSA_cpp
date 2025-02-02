# Notes
'''
1. Hash function : code to convert key (a character) to a value (number)
2. Condition on an hash function : Given a string, return the same number always i.e consistency
3. Collision : Two keys have the same hash value. This is resolved by chaining values at the mem location given by the hash function.
a reference to an array is stored at the memory location given by the hash function. a linear search is done to retrieve the values which are chained at the location.
4. In the worst case, all the elements could end up at single location and it becomes an array search with search time complexity of O(N).
It is better to design a hash function that distributes the values uniformly across the memory locations.
5. Hash table's efficiency is determined by : 1. Amount of data to store 2. Amount of cells available 3. Hashing function used.
6. Hash table's efficiency increases with reduction in collisions. But optimizing for reduction in collisions leads to more memory consumption.
7. Load factor : number of values stored in the hash map divided by the number of cells created. A general thumb of rule is to maintain a load factor of 0.7.
'''

# Hash tables for speed

array = [14,67,90,42,101]

elem = 42

def elem_search(array, elem):
    for i in array:
        if i == elem:
            return True
    return False

print(elem_search(array, elem))

def elem_search_hash(hash_table, elem):
    return hash_table[elem]

hash_table = {}
for i in array:
    hash_table[i] = True

print(elem_search_hash(hash_table, elem))
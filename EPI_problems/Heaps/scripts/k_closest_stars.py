# Consider a coordinate system for the Milky Way, in which Earth is at (0,0,0). Model stars as points,
# and assume distances are in light years. The Milky Way consists of approximately 1012 stars, and
# their coordinates are stored in a file.
# How would you compute the k stars which are closest to Earth?

# if we have RAM , we can download the entire dataset, sort the stars and choose the first k stars
# or there are also methods to split the dataset such that stars before index k have less distance
# we could read it online and have a heap to store k elements which are of less distance
import math
import heapq
class Star:
    def __init__(self, x, y, z):
        self.x, self.y, self.z = x, y, z
    @property
    def distance (self) :
        return math.sqrt(self.x*2 + self.y**2 + self.z**2)
    def __lt__(self, rhs):
        return self.distance < rhs.distance

def find_closest_stars(stars, k):
    max_heap = []

    for star in stars:
        heapq.heappush(max_heap, (-star.distance, star))
        if len(max_heap) == k+1: # more than k stars in max_heap
            heapq.heappop(max_heap)
    return [s[1] for s in heapq.nlargest(k, max_heap)]


if __name__ == "__main__":
    s1 = Star(3,4,1)
    s2 = Star(9,0,5)
    s3 = Star(0,1,1)
    s4 = Star(8,1,4)
    s5 = Star(7,1,1)
    s6 = Star(9,0,1)

    stars = [s1,s2,s3,s4,s5,s6]

    k = 3

    k_closest_stars = find_closest_stars(stars, k)
    print(k_closest_stars)
    
    

    
# program to find the area of intersection of rectangle
from collections import namedtuple

Rectangle = namedtuple('Rectangle', ('x','y','width', 'height'))

def is_intersect(R1 : Rectangle, R2 : Rectangle):
    return (R1.x <= R2.x + R2.width and R1.x + R1.width >= R2.x
            and R2.y <= R2.y + R2.height and R1.y + R1.height >= R2.y)


def intersect_rectangles(R1 : Rectangle, R2 : Rectangle):
    if not is_intersect(R1, R2):
        return Rectangle(0,0,-1,-1) # no intersection
    return Rectangle(
        max(R1.x, R2.x),
        max(R1.y, R2.y),
        min(R1.x + R1.width, R2.x + R2.width) - max(R1.x, R2.x),
        min(R1.y + R1.height, R2.y + R2.height) - max(R1.y, R2.y)
    ) 

if __name__ == "__main__":
    R1 = Rectangle(3,4,2,2)
    R2 = Rectangle(2,5,3,3)
    print(intersect_rectangles(R1,R2))
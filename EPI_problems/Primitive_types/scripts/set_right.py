# Right propagate the rightmost set bit in x, e.9., tums (01010000)2 to (01011111)2.

def set_right(x):
    return x | (x - 1)

if __name__ == "__main__":
    print(bin(set_right(0b01010000)))
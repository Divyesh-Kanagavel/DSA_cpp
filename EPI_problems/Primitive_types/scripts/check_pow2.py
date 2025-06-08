#Test if x is a power of 2

def is_pow_two(x):
    if x == 0:
        return False
    return (x & x - 1) == 0

if __name__ == "__main__":
    print(is_pow_two(8))
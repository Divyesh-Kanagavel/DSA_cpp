# script to count number of bit 1 in a positive integer

def count_onebit(n:int) -> int:
    """
    Count the number of 1 bits in the binary representation of a positive integer.

    :param n: A positive integer
    :return: The count of 1 bits in the binary representation of n
    """
    if n < 0:
        raise ValueError("Input must be a positive integer")
    
    if (not isinstance(n, int)):
        raise ValueError("only integer supported!")

    
    count = 0
    while n :
        count += n & 1
        n >>= 1
    return count

if __name__ == "__main__":
    print(count_onebit(3))


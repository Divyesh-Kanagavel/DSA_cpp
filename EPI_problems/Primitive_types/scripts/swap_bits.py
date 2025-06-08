# brute force approach => use bit shift to get the required bit , 
# store it in a local variable and perform swapping

# a more succint approach is to check if swap is required and just 
# flip the bit if required

def swap_bits(x, i, j):
    # check if bit swap is required
    if (x >> i) & 1 != (x >> j) & 1:
        # Construct a bit mask with only the bits at i and j active and others 0
        # xor the bit mask with x to flip the bits, since xor flips the bits
        bit_mask = (1 << i) | (1 << j)
        x ^= bit_mask
    return x

# tests
if __name__ == "__main__":
    x = 0b00010011
    print("before swapping x = {} and in binary = {}".format(x, bin(x)))
    x = swap_bits(x, 1, 5)
    print("after swapping first and fifth bits, x = {} and in binary = {}".format(x,bin(x)))

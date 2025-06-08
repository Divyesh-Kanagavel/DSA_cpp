# program to reverse the bits of a 64 bit unsigned integer
# approach used : split the 64 bit integer as 4 16 bit integers (y3 y2 y1 y0)
# if y3', y2', y1' y0' are the reverses of each of the 16 bit integers stored
# in a LUT, we could construct the result as (y0', y1' y2', y3')
PRECOMPUTED_LUT = {}
# function to swap bits
def swap_bits(x, i, j):
    # check if bit swap is required
    if (x >> i) & 1 != (x >> j) & 1:
        # Construct a bit mask with only the bits at i and j active and others 0
        # xor the bit mask with x to flip the bits, since xor flips the bits
        bit_mask = (1 << i) | (1 << j)
        x ^= bit_mask
    return x

# reverse a 16 bit integer
def reverse_integer16(x):
    i = 15
    j = 0
    while(i >= j):
        x = swap_bits(x, i, j)
        i -= 1
        j += 1
    
    return x

def reverse_integer16_optimized(x):
    reversed_x = 0
    for _ in range(16):
        reversed_x = (reversed_x << 1) | (x & 1)
        x >>= 1
    return reversed_x


def create_LUT():
    # create a lut for all 16 bit integers with their reverse
    for i in range(2**16):
        PRECOMPUTED_LUT[i] = reverse_integer16(i)


# function to reverse 64 bit integer
def reverse_integer64(x):
    MASK_SIZE = 16
    BIT_MASK = 0xFFFF

    y3 = PRECOMPUTED_LUT[(x & BIT_MASK)] << (3 * MASK_SIZE)
    y2 = PRECOMPUTED_LUT[(x >> MASK_SIZE) & BIT_MASK] << (2 * MASK_SIZE)
    y1 = PRECOMPUTED_LUT[(x >> (2 * MASK_SIZE)) & BIT_MASK] << MASK_SIZE
    y0 = PRECOMPUTED_LUT[(x >> (3 * MASK_SIZE)) & BIT_MASK]

    return (y3 | y2 | y1 | y0)

# tests
if __name__ == "__main__":
    # first test the 16 bit reversal
    print(bin(reverse_integer16(0b1110101010101000)))
    print(bin(reverse_integer16_optimized(0b1110101010101000)))
    create_LUT()
    print(reverse_integer64(121))


        
            



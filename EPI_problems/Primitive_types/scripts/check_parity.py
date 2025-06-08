# script to check the parity of a number in binary format
# parity = 1, if number of 1 bits is odd, else even
# skipping the input validity check since we are interested in algos here.
# Solution 1 : Brute force algorithm , time complexity : O(n) , where
# n is number of bits in the number
def check_parity_bf(x : int) -> bool :
    result = 0
    while x:
        result ^= x & 1
        x >>= 1
    return result

# other elegant solutions
# Solution 2 : bit fiddling trick -> at each iteration , 
# the lowest set bit is erased
# x & x -1 -> erases the lowest bit
def check_parity_bit_fiddle(x : int) -> bool :
    result = 0
    while x:
        result ^= 1
        x &= x - 1
    return result

# another efficient way of computing parity is to construct a 
# lookup table and use it.
# constructing a LUT for 2^64 integers is not feasible.
# since the computation of parity is associative, we could construct
# 4 LUT for 2^16 integers each and combine the results to get final result
PRECOMPUTED_16BIT = {}

MASK_SIZE = 16
BIT_MASK = 0xFFFF
def precompute_LUTS():
    for i in range(2**MASK_SIZE):
        PRECOMPUTED_16BIT[i] = check_parity_bit_fiddle(i)

def check_parity_lut(x : int) -> bool :
    return (PRECOMPUTED_16BIT[x >> (3 * MASK_SIZE)] ^
           PRECOMPUTED_16BIT[(x >> (2 * MASK_SIZE)) & BIT_MASK] ^ 
           PRECOMPUTED_16BIT[(x >> MASK_SIZE) & BIT_MASK] ^ 
           PRECOMPUTED_16BIT[x & BIT_MASK])
          
# tests
if __name__ == "__main__":
    print(check_parity_bit_fiddle(0b001001011001))
    precompute_LUTS()
    print(check_parity_lut(0b001001011001))
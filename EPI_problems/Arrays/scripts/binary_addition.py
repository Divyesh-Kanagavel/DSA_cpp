# Write a program which takes as input two strings s and f of bits encodingbinary numbers
# Bs, and Bt, respectively, and refurns a new string of bits representing the number Bs + Bt.

# the solution i have written is correct, but there is a more elegant and pythonic way as well

def binary_sum(a,b,carry):
    if a == '0' and b == '0' and carry == '0':
        return ('0','0')
    if a == '0' and b == '0' and carry == '1':
        return ('0','1')
    if a == '0' and b == '1' and carry == '0':
        return ('0','1')
    if a == '0' and b == '1' and carry == '1':
        return ('1','0')
    if (a == '1') and (b == '0') and (carry == '0'):
        return ('0','1')
    if a == '1' and b == '0' and carry == '1':
        return ('1','0')
    if a == '1' and b == '1' and carry == '0':
        return ('1','0')
    if a == '1' and b == '1' and carry == '1':
        return ('1','1')

def add_two_bins(Bt, Bs):
    # we will first append 0s to the string which has lesser number of digits
    if len(Bt) > len(Bs):
        num_Bs = "0"*(len(Bt)-len(Bs)) + Bs
        num_Bt = Bt
    elif len(Bt) < len(Bs):
        num_Bt = "0"*(len(Bs)-len(Bt)) + Bt
        num_Bs = Bs
    else:
        num_Bt = Bt
        num_Bs = Bs
    result = ""
    carry = '0'
    for i in reversed(range(len(num_Bt))):
        carry, add = binary_sum(num_Bt[i], num_Bs[i], carry)
        result = add + result
    if carry == '1':
        result = carry + result
    return result

# pythonic elegant way
def binary_sum2(a,b,carry):
    int_a = int(a)
    int_b = int(b)
    int_carry = int(carry)
    total_sum = int_a + int_b + int_carry
    sum_bit = str(total_sum % 2)
    carry_bit = str(total_sum // 2)
    return carry_bit, sum_bit

def add_two_bins2(a,b):
    max_len = max(len(a), len(b))
    a_padded = a.zfill(max_len) # prepend string with leading zeros
    b_padded = b.zfill(max_len)

    result_bits = []
    carry = '0'
    for i in reversed(range(max_len)):
        current_bit_a = a_padded[i]
        current_bit_b = b_padded[i]
        carry, sum_bit = binary_sum2(current_bit_a, current_bit_b, carry)
        result_bits.append(carry)
    if carry == '1':
        result_bits.append(carry)
    return "".join(reversed(result_bits))

if __name__ == "__main__":
    test_cases = [
        ("11111", "11111", "111110"),  # 31 + 31 = 62
        ("101", "10", "111"),          # 5 + 2 = 7
        ("1", "0", "1"),              # 1 + 0 = 1
        ("0", "0", "0"),              # 0 + 0 = 0
        ("1", "1", "10"),             # 1 + 1 = 2
        ("1000", "1", "1001"),        # 8 + 1 = 9
        ("111", "1", "1000"),         # 7 + 1 = 8
        ("0", "101", "101")           # 0 + 5 = 5
    ]

    for Bs_test, Bt_test, expected in test_cases:
        result = add_two_bins(Bs_test, Bt_test)
        print(f"Bs: {Bs_test}, Bt: {Bt_test} -> Result: {result}, Expected: {expected}")
        assert result == expected, f"FAILED: {Bs_test} + {Bt_test}. Expected {expected}, Got {result}"
    print("All test cases passed!")
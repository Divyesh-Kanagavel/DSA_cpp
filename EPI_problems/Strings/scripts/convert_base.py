# Write a program that performs base conversion. The input is a string, an integer b1, and another
# integer b2. The string represents an integer in base br. The output should be the string representing
# the integer in base b2
# 2 <= b1,b2 <= 16

# time complexity : O(n(1+log_b2(b1)))
# idea : convert string in base b1 to a standard format like Hexadecimal number.
# convert standard number into string of base b2
import functools
import string
def convert_base(s, b1, b2):
    def construct_num_b2(num, b2):
        return ('' if num == 0 else construct_num_b2(num // b2, b2) + 
                string.hexdigits[num % b2].upper())
    num = functools.reduce(
        lambda n,c : n * b1 + string.hexdigits.index(c.lower()),
        s[s[0] == '-':],0
    )
    return ('-' if s[0] == '-' else '') + ('0' if num == 0 else 
                                           construct_num_b2(num, b2))

    




# test
if __name__ == "__main__":
    print(convert_base("620", 8, 2))
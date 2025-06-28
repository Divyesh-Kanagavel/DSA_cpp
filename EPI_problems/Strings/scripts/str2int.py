# Implement an integer to string conversion function, and a string to integer conversison function,
import functools
import string
def int2str(x):
    is_negative = False
    if x < 0:
        x, is_negative = -x, True
    
    s = []
    
    while(x):
        s.append(chr(ord('0') + x % 10))
        x //= 10
        if x == 0:
            break
    
    return ('-' if is_negative else '') + ''.join(reversed(s))


def str2int(s):
    # takes three arguments : a function which is applied on a iterable, iterable, initializer
    return functools.reduce(
        lambda running_sum, c : running_sum * 10 + string.digits.index(c),
        s[s[0] == '-':], 0
    ) * (-1 if s[0] == '-' else 1)

# assuming valid inputs 
if __name__ == "__main__":
    print(int2str(234), type(int2str(234)))
    print(str2int("343"), type(str2int("343")))

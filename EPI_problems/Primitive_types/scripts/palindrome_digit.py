# check if a integer is palindrome
# one approach is to reverse the digits and check if the reverse is the same
import math
def reverse_integer(x):
    result, x_remaining = 0, abs(x)
    while x_remaining:
        result = result * 10 + x_remaining % 10
        x_remaining //= 10
    return -result if x < 0 else result

def check_palindrome(x):
    if x <= 0: 
        return x == 0
    return x == reverse_integer(x)

# another approach is to extract trailing digit and leading digit and compare
# if they are same. if not, return false, else remove them and coninue the same process
# for the remaining digits in the number
# O(n) time complexity and O(1) space complexity
def check_palindrome2(x):
    if x <= 0:
        return x == 0
    num_digits = math.floor(math.log10(x)) + 1
    msd_mask = 10 ** (num_digits - 1)
    for _ in range(num_digits // 2):
        if x // msd_mask != x % 10:
            return False
        x = x % msd_mask
        x //= 10
        msd_mask //= 100 # since two digits are removed
    return True


if __name__ == "__main__":
    print(check_palindrome(1221))
    print(check_palindrome2(1221))



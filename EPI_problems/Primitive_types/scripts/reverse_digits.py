# reverse the digits of an integer
# brute force approach : convert to a string and reverse the string
# a better solution exists without going to strings
# recursively divide by 10, extracting most significatnt digit and thereby reversing the number
import unittest
def reverse_integer(x):
    result, x_remaining = 0, abs(x)
    while x_remaining:
        result = result * 10 + x_remaining % 10
        x_remaining //= 10
    return -result if x < 0 else result

class TestReverseInteger(unittest.TestCase):

    def test_zero(self):
        x = 0
        self.assertEqual(reverse_integer(0), 0)

    def test_positive(self):
        x = 890
        self.assertEqual(reverse_integer(890), 98)

    def test_negative(self):
        x = -431
        self.assertEqual(reverse_integer(x), -134)

# tests 
if __name__ == "__main__":
    unittest.main()
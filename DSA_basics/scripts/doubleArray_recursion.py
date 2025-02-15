import unittest

class TestDoubleArray(unittest.TestCase):
    def test_empty_array(self):
        arr = []
        double_array(arr)
        self.assertEqual(arr, [])

    def test_zero(self):
        arr = [0]
        double_array(arr)
        self.assertEqual(arr, [0])
    def test_neg(self):
        arr= [-1,-4,-6]
        double_array(arr)
        self.assertEqual(arr, [-2,-8,-12])
    def test_general(self):
        arr = [4,-1,0,120,54]
        double_array(arr)
        self.assertEqual(arr, [8,-2,0,240,108])
    def test_None(self):
        arr = None
        double_array(None)
        self.assertEqual(arr, None)   

# in place doubling of array using recursion
def double_array(arr,index=0):
    if arr is None:
        return
    if index >= len(arr):
        return
    arr[index] *= 2
    double_array(arr, index+1)
    



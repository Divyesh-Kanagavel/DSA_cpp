# string reversal through recursion

import unittest

def stringReversalWrapper(string):
    if not isinstance(string, str):
        return None
    if string is None:
        return None
    if len(string) == 0:
        return ""
    return stringReversal(string)
    

def stringReversal(string):
    if len(string) == 1:
        return string
    return stringReversal(string[1:]) + string[0]

class TestStringReversal(unittest.TestCase):
    def testEmptyString(self):
        self.assertEqual(stringReversalWrapper(""),"")
    
    def testNone(self):
        self.assertEqual(stringReversalWrapper(None),None)
    
    def testWrongType(self):
        self.assertEqual(stringReversalWrapper(1),None)

    def testSinglechar(self):
        self.assertEqual(stringReversalWrapper("a"),"a")
    
    def testGeneral(self):
        self.assertEqual(stringReversalWrapper("divyesh"), "hseyvid")


# Implement a function which takes as input a string s and retums true if s is a palindromic string.
# naive solution -> reverse the string and check reversed string and input string are the same
# O(n) time complexity and O(n) space compelexity
# better approach -> two pointer algorithm
import string
def is_palindrome(s):
    i, j = 0, len(s)-1
    while i<j:
        while not s[i].isalnum() and i < j:
            i += 1
        while not s[j].isalnum() and i < j:
            j -= 1
        if s[i] != s[j]:
            return False
        i,j = i+1, j-1
    return True
        

if __name__ == "__main__":
    s = "A-CBBA"
    print(is_palindrome(s))
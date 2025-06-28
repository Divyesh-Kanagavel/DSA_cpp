# in this context ~i is -(i+1)
def is_palindrome(s):
    return all(s[i] == s[~i] for i in range(len(s)//2))

if __name__ == "__main__":
    s = "siris"
    print(is_palindrome(s))


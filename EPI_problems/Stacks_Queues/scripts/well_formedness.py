# Write a program that tests if a string made up of the characters '(', ')' ,'I' ,'l' /'l' and")' is well-formed

def is_wellformed(s):
    left_chars = []
    lookup = {
        '(':')',
        '[':']',
        '{':'}'
    }
    for c in s:
        if c in lookup:
            left_chars.append(c)
        elif not left_chars or lookup[left_chars.pop()]!=c: # either stack is empty or there is no matching left char
            return False
    return not left_chars

if __name__ == "__main__":
    s = "(()[])"
    print(is_wellformed(s))
    
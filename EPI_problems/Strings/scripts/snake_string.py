# Write a program which takes as input a string s and retums the snakestring of s'

def snake_string(s):
    result = []
    # top row populated first
    for i in range(1, len(s), 4):
        result.append(s[i])
    # mid row second
    for i in range(0, len(s), 2):
        result.append(s[i])
    for i in range(3, len(s), 4):
        result.append(s[i])
    return "".join(result)

def snake_string_pythonic(s):
    return s[1::4] + s[0::2] + s[3::4]

if __name__ == "__main__":
    s = "Hello world!"
    print(snake_string(s))
    print(snake_string_pythonic(s))
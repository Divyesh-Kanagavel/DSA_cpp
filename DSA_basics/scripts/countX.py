# program to count X's in a string using recursion

def count_X(string):
    if len(string) == 0:
        return 0
    if string[0] == 'x' or string[0] == 'X':
        return 1 + count_X(string[1:])
    else:
        return count_X(string[1:])

string = "Xaxx"
print(count_X(string))
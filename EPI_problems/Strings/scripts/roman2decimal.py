# Write a program which takes as input a valid Roman number string s and retums the integer it
# corresponds to.
# naive approach : start from left to right -> if s[i+1] > s[i], club the two and find the resultant
# better approach : start from end -> if s[i+1] < s[i], subtract the element else add
import functools
def roman_to_integer(s):
    T = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
    return functools.reduce(
        lambda val, i : val + (-T[s[i]] if T[s[i]] < T[s[i+1]] else T[s[i]]),
        reversed(range(len(s)-1)), T[s[-1]]
    )

if __name__ == "__main__":
    roman = "MCCXC"
    print(roman_to_integer(roman))
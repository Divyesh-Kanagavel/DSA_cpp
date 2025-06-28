# Write a program that takes as input a string of Roman number symbols and checks whether
# that string is valid.

def is_valid_roman(numeral):
    T = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
    i = len(numeral)-1
    while (i-2)>=0:
        if numeral[i-2] < numeral[i-1] and numeral[i-1] < numeral[i]:
            return False
        else:
            i -= 1
    return True 

if __name__ == "__main__":
    roman = "XXIVX"
    print(is_valid_roman(roman))
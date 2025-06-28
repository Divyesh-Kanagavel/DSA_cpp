#  Write a program that takes as input a positive integer n and returns a shortest valid simple
# Roman number string representing n.

def integer_to_roman(num):
    T = {"I":1,
         "IV":4,
         "V":5,
         "IX":9, 
         "X":10,
         "XL":40,
         "L":50,
         "XC":90,
         "C":100,
         "CD":400,
         "D":500,
         "CM":900,
         "M":1000}
    if num <= 0:
        return ""
    result = []
    for key in reversed(list(T.keys())):

        while num >= T[key]:
            result.append(key)
            num -= T[key]
    
    return "".join(result)





if __name__ == "__main__":
    num = 24
    print(integer_to_roman(num))
# compute x ** y, where x is a double and y is an integer. ignore underflow
# overflow for now
# brute force is to do x^2 = x * x, x ^ 3 = x^2 * x and so on. 
# takes y-1 multiplications to achieve x ** y -> O(2^n) -> n is the number of bits to represent y

def compute_exponent(x,y):
    result, power = 1.0, y
    if y < 0:
        result,power = 1.0/x, -power
    
    while power:
        if power & 1:
            result *= x
        x, power = x * x, power >> 1
    
    return result

# test
if __name__ == "__main__":
    x = 4.3
    y = 2
    print(compute_exponent(x,y))
    print(x ** y)
        
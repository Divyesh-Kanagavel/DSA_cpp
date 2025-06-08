#Compute x mod a power of two, e.g., retums 13 for 77 mod 64.

def mod_powertwo(x,n):
    return (x & ((1<<n) - 1))

if __name__ == "__main__":
    print(mod_powertwo(77,6))
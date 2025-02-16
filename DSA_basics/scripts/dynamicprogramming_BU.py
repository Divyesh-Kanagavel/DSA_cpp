# dynamic programming is a technique to improve upon the bane of recursion
# there is another method apart from memoization - iteration
# though it looks like a technique already seen many times, here it is 
# used in places where recursion achieves elegance and is intuitive but
# is expensive (timewise and spacewise)

def fib(n):
    if n==0:
        return 0
    a = 0
    b = 1
    for i in range(1,n):
        temp = a
        a = b
        b = temp + b
    return b

print(fib(0))

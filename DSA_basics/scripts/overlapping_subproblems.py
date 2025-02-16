# consider a fibonacci series 
# f(0) = f(1) = 1
# f(n) = f(n-1) + f(n-2)

# the problem is usually solved by recursion

def fibonacci(n):
    if n == 0 or n == 1:
        return n
    return fibonacci(n-1) + fibonacci(n-2)

print(fibonacci(6))

# the solution looks very neat. but there is a problem. each call to 
# fibonacci function recursive calls two fibonacci's triggering a 
# time complexity of O(2^N). Like in the previous max problem,
# we cannot store it in a single variable because we are calling fibonacci's
# with two different arguments.

# this is the problem of overlapping subproblems. 
# solved by dynamic programming approach of memoization
# store the recurrently usable values in a hashmap and use it before calling a recursive function

def fiboOptimized(n, memo = {}):
    if n==0 or n==1:
        return n
    if not memo.get(n):
        memo[n] = fiboOptimized(n-1, memo) + fiboOptimized(n-2,memo)
    return memo[n]

print(fiboOptimized(6))
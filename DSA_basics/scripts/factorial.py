# calculating the factorial of number using recursion - both top-down and bottom-up approach
# bottom up approach - similar to a loop - not so elegant
# top down approach - achievable through recursion - elegant

# bottom up function
def fact_BU(n, i=1, fact=1):
    if n == 0:
        return 1
    if i > n:
        return fact
    return fact_BU(n, i+1, i*fact)

factorial = fact_BU(6)
print(factorial)

# top down function
def fact_TD(n):
    if n == 0 or n == 1:
        return 1
    return n * fact_TD(n-1)
factorial = fact_TD(0)
print(factorial)
# memoization of golomb sequence

# without memoization

def golomb(n):
    print("recursion")
    if n == 0:
        return 0
    if n == 1:
        return 1
    return 1 + golomb(n - golomb(golomb(n - 1)))

def golomb_memoized(n,memo={}):
    print("recursion ")
    if n==0 or n==1:
        return n
    if not memo.get(n):
        memo[n]  = 1 + golomb_memoized(n - golomb_memoized(golomb_memoized(n-1)))
    return memo[n]


# tests
print(golomb_memoized(6))

sum_diff = 0
#for i in range(50):
    #sum_diff += (golomb(i) - golomb_memoized(i))
#print(sum_diff)


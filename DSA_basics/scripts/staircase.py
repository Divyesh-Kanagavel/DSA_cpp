# there are N steps
# we can climb up 1 , 2 or 3 steps at a time. 
# number of possible ways to reach top

def staircase(n):
    if n < 0:
        return 0
    if n == 1 or n==0:
        return 1
    return staircase(n-1) + staircase(n-2) + staircase(n-3)

print(staircase(2))
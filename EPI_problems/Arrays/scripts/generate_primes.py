# Write a program that takes an integer argument and returns all the primes between 1 and that
# integer. For example, if the input is 18, you should returna <2,3,5,7,77,13,17>
# brute force approach : iterate from 2 to N. for each i, iterate from 0 to sqrt(i), O(N^3/2)

# a more optimized approach is to have a boolean which check if a number is prime
# for every prime number, put all its multiples till N as false. and append to another array if it is prime
# time complexity : O(nlog(log(n))) -> n/2 + n/3 + n/5 + n/7 + ...
def generate_primes(N):
    primes = [] # array to store the primes
    is_primes = [False, False] + [True] * (N-1)
    for i in range(2,N+1):
        if is_primes[i]:
            primes.append(i)
            for i in range(i,N+1,i):
                is_primes[i] = False
    return primes

# test
if __name__ == "__main__":
    num = 15
    print(generate_primes(num))

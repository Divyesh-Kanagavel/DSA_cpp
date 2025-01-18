import time as time
from itertools import product
eng_letters = 'abcdefghijklmnopqrstuvwxyz'

def brute_force(num):

    if num == 1:
        return list(eng_letters)
    smaller_permutation = brute_force(num-1)
    return [letter + perm for letter in eng_letters for perm in smaller_permutation]

def brute_force_itertools(num):
    # Use product to generate all combinations of 'eng_letters' repeated 'num' times
    return [''.join(p) for p in product(eng_letters, repeat=num)]

def brute_force_tuples(num):
    results = [(letter,) for letter in eng_letters]

    for _ in range(num-1):
        results = [prev_tuple + (letter,) for prev_tuple in results for letter in eng_letters]
    return results
start = time.time()
results = brute_force_tuples(2)
print(time.time() - start)
print(results)









# the brute force is very inefficient because it has a time complexity of 
# O(a^n) , where a is a constant like in this case a = 26. 
# for every one element added, the time complexity is increased by a times.




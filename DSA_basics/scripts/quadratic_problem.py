# find if array has duplicates

# algo with quadratic time complexity : O(n^2)
def hasduplicateValue(array):
    steps = 0 # counter to illustrate complexity
    for i in range(len(array)):
        for j in range(len(array)):
            steps += 1
            if (i!=j) and (array[i]==array[j]):
                return True
    print(steps)
    return False

def hasduplicateValueLinear(array):
    steps = 0
    existingValue = [0] * len(array)
    for i in range(len(array)):
        steps+=1
        if (existingValue[i] == 1):
            return True
        else:
            existingValue[i] = 1
    print(steps)
    return False

print(hasduplicateValue([3,4,5,1,0]))

print("---------")

print(hasduplicateValueLinear([3,4,5,1,0]))


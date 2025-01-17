def greatestNumber(array): 
    for i in array:
       # Assume for now that i is the greatest
        isIValTheGreatest = True
        for j in array:
        # If we find another value that is greater than i, # i is not the greatest:
            if j > i:
                isIValTheGreatest = False
        if isIValTheGreatest:
            return i

def greatestNumberLinear(array):
    max = array[0]
    for i in range(1,len(array)):
        if array[i] > max:
            max = array[i]
    return max

print(greatestNumberLinear([7,1,3,9,8,5]))
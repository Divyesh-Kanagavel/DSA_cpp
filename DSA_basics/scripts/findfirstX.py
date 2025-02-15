# find the index of first occurence of x in array using recursion

def findfirstX(string, index=0):
    if len(string) == 0:
        return -1
    if string[0] == 'x':
        return index
    return findfirstX(string[1:], index+1)

string = "abcdflxop"
print(findfirstX(string))



        
        
    
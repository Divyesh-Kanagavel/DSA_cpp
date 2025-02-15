# given a string , create all possible anagrams from that string

def anagrams(string):
    if len(string) == 0:
        return []
    if len(string) == 1:
        return [string]
    collections = []
    substring_anagrams = anagrams(string[1:])
    for i in substring_anagrams:
        for j in range(len(i)+1):
            collections.append(i[:j] + string[0]+ i[j:])
    return collections
       

print(anagrams("abcd"))


    
    
    

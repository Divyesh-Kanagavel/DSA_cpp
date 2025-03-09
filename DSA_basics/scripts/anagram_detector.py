# check if two strings are anagrams of each other
# three approaches with increasingly better time complexities are listed

# first approach -> in outer loop, iterate over str1
# in inner loop, iterate over str2 , if a character in str1 is in str2, remove it from str2
# this way, the time complexity is O(n*m)
def anagram_detector_v1(str1, str2):
    str2_array = list(str2)

    for char in str1:
        if len(str2_array) == 0:
            return False

        for j in range(0,len(str2_array)):
            if char == str2_array[j]:
                str2_array.pop(j)
                break
    
    return len(str2_array) == 0

# approach 2 : sort both the string and compare them. O(nlogn + mlogm) time complexity
def anagram_detector_v2(str1, str2):
    str1_sorted = list(str1)
    str2_sorted = list(str2)
    str1_sorted.sort()
    str2_sorted.sort()
    return str1_sorted == str2_sorted

# approach 3 : use hash tables to store elements of both the strings O(n+m)
def anagram_detector_v3(str1, str2):
    str1_hash = {}
    str2_hash = {}
    for char in str1:
        if str1_hash.get(char):
            str1_hash[char] += 1
        else:
            str1_hash[char] = 1
    for char in str2:
        if str2_hash.get(char):
            str2_hash[char] += 1
        else:
            str2_hash[char] = 1
    
    return str1_hash == str2_hash



# tests 
str1 = "listen"
str2 = "silent"

print(anagram_detector_v1(str1, str2))
print(anagram_detector_v2(str1, str2))
print(anagram_detector_v3(str1, str2))
            
        

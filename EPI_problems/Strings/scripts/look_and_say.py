# Write a Program that takes as input an integer r and retums the nth integer in the look-and-say
# sequence. Return the result as a string.

def look_and_say(n):
    def next_number(s):
        result, i  = [], 0
        while i < len(s):
            count = 1
            while i+1 < len(s) and s[i] == s[i+1]:
                count += 1
                i+=1
            result.append(str(count)+s[i])
            i+=1
        return ''.join(result)

            

    s = '1'
    for _ in range(1,n):
        s = next_number(s)
    return s

if __name__ == "__main__":
    print(look_and_say(6))
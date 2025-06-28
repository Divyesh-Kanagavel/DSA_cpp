# Implement a function for reversing the words in a string s.
import string
def reverse_string(s):
    # reverse the whole string
    s.reverse()

    def reverse_word(s, start, end):
        while start < end:
            s[start], s[end] = s[end], s[start]
            start, end = start + 1, end - 1
    
    start = 0
    while True:
        try:
            end = s.index(' ',start)
        except ValueError:
            break
        reverse_word(s, start, end - 1)
        start = end + 1
    # reverse the last word
    reverse_word(s, start, len(s)-1)

if __name__ == "__main__":
    s = "I am a good boy"
    s_list = list(s)
    reverse_string(s_list)
    print(''.join(s_list))




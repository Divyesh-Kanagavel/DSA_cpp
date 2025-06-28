# Write a program which takes as input a phone number, specified as a string of digits, and returns
# all possible character sequences that correspond to the phone number. The cell phone keypad is
# specified by a mapping that takes a digit and returns the corresponding set of characters. The
# character sequences do not have to be legal words or phrases.

MAPPING = ('0','1','ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'XYZ')

# the algorithm has time complexity of O(4^n * n). 
# the recursive relationship is T(n) <= 4 T(n-1) because for each digit, 
# the next level could at maximum have 4 characters.
# hence O(4^n). and we have n such recursions happening for each digit
def phone_mnemonic(phone_number):
    def mnemonic_helper(digit):
        if digit == len(phone_number):
            mnemonics.append(''.join(partial_mnemonic))
        else:
            for c in MAPPING[int(phone_number[digit])]:
                partial_mnemonic[digit] = c
                mnemonic_helper(digit+1)
        
    mnemonics , partial_mnemonic = [], [0] * len(phone_number)
    mnemonic_helper(0)
    return mnemonics

if __name__ == "__main__":
    phone_number = "01876"
    print(phone_mnemonic(phone_number))


        
        

    

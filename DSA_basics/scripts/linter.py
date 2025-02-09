# linter : a program which inspects source code and finds syntactical errors
# in this program, the focus is on one aspect of linting - opening and closing of braces

# three sources of errors
# 1. missing opening brace
# 2. missing closing brace for an opening brace
# 3. wrong closing brace for an immediately preceding open brace

# stacks can be used to design a beautiful linter for this problem
# push the opening braces in the stack, if any other character is encountered,
# ignore and move on. if a closing brace is encountered, pop the top element 
# from the stack and check if it matches the closing brace -> fine, else -> error 3
# if the stack is empty , error 1, because we have no opening brace
# if the entire string is parsed but stack is not empty , error 2

expression = "var x = {y : [1,2,3]})" # javascript expression


class Linter:

    def __init__(self):
        self.stack = []
        self.brace_pair = {'{':'}', '[':']','(':')'}
    
    def lint(self, text):
        for char in text:
            if self.is_opening_brace(char):
               self.stack.append(char)
            elif self.is_closing_brace(char):
                popped_char = self.stack.pop() if self.stack else None
                if not popped_char:
                    print("Error : missing opening brace")
                    return False
                if self.is_not_matching(popped_char, char):
                    print("Error : wrong closing brace")
                    return False
        if self.stack:
            print("Error : missing closing brace")
            return False
        return True                            

    def is_opening_brace(self,char):
        return char in ['(','{', '[']

    def is_closing_brace(self,char):
        return char in [')','}', ']']
    
    def is_not_matching(self,opening_brace, closing_brace):
        return closing_brace != self.brace_pair[opening_brace]

linter = Linter()

if linter.lint(expression):
    print("No errors found")
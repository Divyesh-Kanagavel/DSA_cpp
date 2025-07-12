# Write a program that takes an arithmetical expression in RPN and retums the number that the
# expression evaluates to.

# reverse polish notation
def evaluate(rpn_expression):
    intermediate_results = []
    DELIMITER = ','
    OPERATORS = {
        '+':lambda y, x : x + y, 
        '-':lambda y, x : x - y, 
        '*':lambda y, x : x * y, 
        '/':lambda y, x : int(x / y)
    }
    for operator in rpn_expression.split(DELIMITER):
        if operator in OPERATORS:
            intermediate_results.append(OPERATORS[operator](
                intermediate_results.pop(), intermediate_results.pop()
            ))
        else:
            intermediate_results.append(int(operator))
    
    return intermediate_results[-1]

def evaluate_polish(pn_expression):
    intermediate_results = []
    DELIMITER = ','
    OPERATORS = {
        '+':lambda y, x : x + y, 
        '-':lambda y, x : x - y, 
        '*':lambda y, x : x * y, 
        '/':lambda y, x : int(x / y)
    }

    for operator in reversed(pn_expression.split(DELIMITER)):

        if operator in OPERATORS:
            intermediate_results.append(OPERATORS[operator](
                intermediate_results.pop(), intermediate_results.pop()
            ))
        else:
            intermediate_results.append(int(operator))
    
    return intermediate_results[-1]




if __name__ == "__main__":
    rpn_expression = "3,4,+,2,*,1,+"
    pn_expression = "*,+,2,3,4"
    print(evaluate(rpn_expression))
    print(evaluate_polish(pn_expression))
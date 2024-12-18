def evaluate_postfix(expression):
    operator_set = {'^', '/', '*', '+', '-'}
    evaluation_stack = []
    elements = expression.split()

    for element in elements:
        if element in operator_set:
            operand1 = evaluation_stack.pop()
            operand2 = evaluation_stack.pop()

            if element == '^':
                evaluation_stack.append(operand2 ** operand1)
            elif element == '/':
                evaluation_stack.append(operand2 / operand1)
            elif element == '*':
                evaluation_stack.append(operand2 * operand1)
            elif element == '+':
                evaluation_stack.append(operand2 + operand1)
            elif element == '-':
                evaluation_stack.append(operand2 - operand1)
        else:
            evaluation_stack.append(float(element))
    
    return evaluation_stack[-1]
    

postfix_expr = input("Provide a postfix expression: ")
result = evaluate_postfix(postfix_expr)
print(f"The evaluated result is: {result}")
postfix = "35*62/+4-"
stack = []

for exp in postfix:
    if exp not in ['*', '+', '-', '/']:
        stack.append(exp)
    else:
        x2 = stack.pop()
        x1 = stack.pop()
        r = str(eval(x1 + exp + x2))
        stack.append(r)
    
print(stack)
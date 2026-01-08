import sys
input = sys.stdin.readline

prts = input().rstrip()
stack = []
prev = ''
calc = 0

for ch in prts:
    if ch == '(':
        stack.append('(')
    else:
        stack.pop()
        if prev == '(':
            calc += len(stack) 
        else:        
            calc += 1    
    prev = ch


print(calc)
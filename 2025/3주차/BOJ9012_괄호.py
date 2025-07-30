
import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    
    parentheses = input().strip()
    stack = []
    isDone = True
    
    for e in parentheses:
        if e == '(':
            stack.append(e)
        elif e == ')':
            if not stack:
                isDone = False
                break
            stack.pop()
    if stack:
        isDone = False
    print("YES" if isDone else "NO")
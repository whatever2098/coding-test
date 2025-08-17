import sys
input = sys.stdin.readline

k = int(input())

stack = []
for _ in range(k):
    num = int(input())
    if num == 0 and stack:
        stack.pop()
        continue
    stack.append(num)

total = 0
for e in stack:
    total += e
    
print(total)
        


'''
import sys
input = sys.stdin.readline

k = int(input())
stack = []
total = 0

for _ in range(k):
    x = int(input())
    if x == 0:
        if stack:                 # 문제 보장 있지만 방어적으로
            total -= stack.pop()
    else:
        stack.append(x)
        total += x

print(total)
'''
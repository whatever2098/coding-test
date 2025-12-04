import sys
input = sys.stdin.readline

string = list(input().strip())
N = len(string)
M = int(input())
left = string
right = []

for _ in range(M):
    cmd = input().rstrip()  #수정한 곳
    if cmd ==  'L':
        if left:
            right.append(left.pop())
    elif cmd == 'D':
        if right:
            left.append(right.pop())
    elif cmd == 'B':
        if left:
            left.pop()
    else:
        _, x = cmd.split()      #수정한 곳
        left.append(x)

print(''.join(left + right[::-1]))
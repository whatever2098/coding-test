import sys
input = sys.stdin.readline

arr = [list(map(int, input().split())) for _ in range(2)]

for i in range(2):
    s = 0
    for j in range(4):
        s += arr[i][j]
    print(s / 4, end=" ")
print()

for j in range(4):
    s = 0
    for i in range(2):
        s += arr[i][j]
    print(s / 2, end=" ")
print()

total = 0
for i in range(2):
    for j in range(4):
        total += arr[i][j]
print(total / 8)
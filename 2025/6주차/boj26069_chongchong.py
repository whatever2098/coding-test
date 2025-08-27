import sys
input = sys.stdin.readline

n = int(input())
dancing = {"ChongChong" } #총총이는 처음부터 춤춤.


for _ in range(n):
    a, b = input().split()
    if a in dancing or b in dancing:
        dancing.add(a)
        dancing.add(b)

print(len(dancing))


import sys
input = sys.stdin.readline

def GCD(a, b):
    if b == 0: return a
    return GCD(b, a % b)

def LCM(a, b):
    return a * b // GCD(a, b)


T = int(input())
for _ in range(T):
    A, B = map(int, input().split())
    print(LCM(A, B))
    T -= 1
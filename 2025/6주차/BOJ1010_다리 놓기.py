import sys
import math
input = sys.stdin.readline

def combination(n, r):
    if r > n:
        return 0
    if r == 0 or r == n:
        return 1
    
    result = 1
    for i in range(r):
        result = result * (n - i) // (i + 1)
    return result

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    print(combination(M, N))









# T = int(input())
# for _ in range(T):
#     N, M = map(int, input().split())
#     #print(math.comb(M, N))
    
    
    
    
    
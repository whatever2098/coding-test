import sys
input = sys.stdin.readline

A, B = map(str, input().split())

A_rev = A[2] + A[1] + A[0]
B_rev = B[2] + B[1] + B[0]

A_rev = int(A_rev)
B_rev = int(B_rev)

if A_rev > B_rev:
    print(A_rev)
else: 
    print(B_rev)
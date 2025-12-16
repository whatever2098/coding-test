import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
targets = list(map(int, input().split()))

dq = deque(range(1, N + 1))
count = 0

for target in targets:
    idx = dq.index(target)

    left = idx
    right = len(dq) - idx

    if left <= right:
        for _ in range(left):
            dq.append(dq.popleft())
            count += 1
    else: 
        for _ in range(right):
            dq.appendleft(dq.pop())
            count += 1
    dq.popleft()

print(count)
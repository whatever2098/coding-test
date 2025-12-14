import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
targets = list(map(int, input().split()))

dq = deque(range(1, N + 1))
ans = 0

def rotate_left(dq, k):
    for _ in range(k):
        dq.append(dq.popleft())

def rotate_right(dq, k):
    for _ in range(k):
        dq.appendleft(dq.pop())

for x in targets:
    idx = dq.index(x)          # 0-based
    left = idx
    right = len(dq) - idx

    if left <= right:
        rotate_left(dq, left)
        ans += left
    else:
        rotate_right(dq, right)
        ans += right

    dq.popleft()  # x 제거(이제 맨 앞)

print(ans)

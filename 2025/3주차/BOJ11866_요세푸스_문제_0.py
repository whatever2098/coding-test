import sys
from collections import deque
input = sys.stdin.readline

N, K = map(int, input().split())
q = deque(range(1, N + 1))
result = []

while q:
    q.rotate(-(K - 1))      # 큐를 왼쪽으로 K-1만큼 회전시켜 K번째가 맨 앞에 오게 함
    result.append(q.popleft())  # 맨 앞의 원소를 제거하여 결과에 추가

print("<" + ", ".join(map(str, result)) + ">")  # 출력 형식 맞추기


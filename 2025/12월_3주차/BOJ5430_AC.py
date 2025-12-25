import sys
from collections import deque
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    p = input().strip()          # 수행 함수 문자열 (예: "RDD")
    n = int(input().strip())     # 배열 크기
    arr_str = input().strip()    # 예: "[1,2,3]" 또는 "[]"

    if n == 0:
        arr = deque()
    else:
        arr = deque(map(int, arr_str[1:-1].split(',')))

    is_reversed = False
    error = False

    for cmd in p:
        if cmd == 'R':
            is_reversed = not is_reversed
        else:  # 'D'
            if not arr:
                print("error")
                error = True
                break
            if not is_reversed:
                arr.popleft()
            else:
                arr.pop()

    if not error:
        if is_reversed:
            arr.reverse()
        print("[" + ",".join(map(str, arr)) + "]")

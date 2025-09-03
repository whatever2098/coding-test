import sys
input = sys.stdin.readline

n = int(input())   # 두 번째 칸 입력값

arr = [1, n]       # 시작값 설정

while True:
    nxt = arr[-1] + arr[-2]  # 다음 항 = 마지막 두 항의 합
    if nxt > 100:            # 100 넘으면 중단
        break
    arr.append(nxt)

print(*arr)

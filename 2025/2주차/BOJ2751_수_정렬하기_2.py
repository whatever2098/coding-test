import sys

N = int(input())
#arr = list(map(int, sys.stdin.readline().split()))

#리스트 컴프리헨션으로 N개의 수를 한 줄 씩 입력받는다.
arr = [int(sys.stdin.readline()) for _ in range(N)]  

arr.sort()

for e in arr:
    print(e)
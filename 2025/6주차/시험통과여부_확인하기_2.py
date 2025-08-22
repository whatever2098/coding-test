import sys
input = sys.stdin.readline

count = 0

students = int(input())

for _ in range(students):
    ls = list(map(int, input().split()))  #학생 1명의 4가지 점수 한 줄
    total = 0
    for i in range(4):
        total += ls[i]
    avg = total / 4 #Python 3에서는 / 연산자가 이미 float 나눗셈이므로 float(4)는 불필요합니다.
    if avg >= 60:
        print("pass")
        count += 1
    else:
        print("fail")
print(count)
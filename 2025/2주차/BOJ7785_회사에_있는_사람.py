import sys
input = sys.stdin.readline        # 빠름! 실제로는 sys.stdin.readline() 호출

n = int(input())  # 첫 번째 값은 출입 기록 개수     

s = set()
idx = 1  # data[1]부터 이름과 출입기록이 번갈아 나옴

for _ in range(n):
    name, action = input().split()
    
    if action == "enter":
        s.add(name)
    else:
        s.discard(name)       #remove : 대상이 이미 없으면 KeyError 발생시킴.


    idx += 2  # 다음 (이름, 행동) 쌍으로 이동
    
# 출력: 이름을 사전 역순으로 정렬
for name in sorted(s, reverse=True):
    print(name)    







'''
import sys
input = sys.stdin.readline

n = int(input())
s = set()

for _ in range(n):
    name, action = input().split()
    if action == "enter":
        s.add(name)
    else:
        s.discard(name)  # 없어도 에러 안 남

for name in sorted(s, reverse=True):
    print(name)
'''    
    

import sys
input = sys.stdin.readline

n = int(input())
s = set()

for _ in range(n):
    name, cmd = input().split()
    if cmd == "enter":
        s.add(name)    #set, add()
    else:
        s.discard(name)  #나가면 제거 (없어도 에러 안 남)
        
for name in sorted(s, reverse=True):
    print(name)
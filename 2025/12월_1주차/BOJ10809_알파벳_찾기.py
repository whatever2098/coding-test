import sys
input = sys.stdin.readline

S = input().strip("\n")

for c in range(97, 123):  #숫자 아스키코드 97 ~ 122 까지
    ch = chr(c)
    pos = S.find(ch)
    if pos != -1:
        print(pos, end=' ')
    else: 
        print(-1, end=' ')

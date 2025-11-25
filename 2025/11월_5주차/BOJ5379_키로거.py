import sys
input = sys.stdin.readline

T = int(input())
while(T):
    s = input().strip()
    left = []
    right = []
    for ch in s:
        if ch == '<':
            if left:
                right.append(left.pop())
        elif ch == '>':
            if right:
                left.append(right.pop())
        elif ch == '-':
            if left:
                left.pop()
        else: left.append(ch)

    print(''.join(left + right[::-1]))  
    T -= 1
            
          
    


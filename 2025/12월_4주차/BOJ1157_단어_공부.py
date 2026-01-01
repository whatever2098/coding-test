import sys
input = sys.stdin.readline

text = input().rstrip()

count= [0] * 26

for ch in text:
    ch = ch.upper()
    count[ord(ch) - ord('A')] += 1

max_count = max(count)

if count.count(max_count) > 1:   # 리스트 안에서 값  max_count이 몇 개 있는지 세어줌.
    print('?')
else:
    idx = count.index(max_count)  #count 배열에서 가장 많이 나온 알파벳의 위치
    print(chr(idx + ord('A')))  #인덱스를 다시 문자열로 변환하여 출력
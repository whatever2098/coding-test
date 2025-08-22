# import sys
# input = sys.stdin.readline

# int(input())
# sequence = list(map(int, input().split()))
# x = int(input())

# sequence.sort() #정렬 후

# for i in range(n):
#     if sequence[i] == x:        #이분 탐색?
#         if x #수학적으로 계산하고 싶었다
        
        
        
  #정렬 & 이분탐색     
import sys
import bisect
input = sys.stdin.readline

n = int(input())
sequence = list(map(int, input().split()))
x = int(input())

sequence.sort()
count = 0

for i, v in enumerate(sequence):
    b = x - v
    # v 이후 구간에서 b가 나타나는 [L, R) 길이를 더함
    L = bisect.bisect_left(sequence, b, i + 1)
    R = bisect.bisect_right(sequence, b, i + 1)
    count += (R - L)

print(count)


# #chatGPT 추천 답
# import sys
# input = sys.stdin.readline

# n = int(input())
# sequence = list(map(int, input().split()))
# x = int(input())

# sequence.sort()

# left, right = 0, n - 1
# count = 0

# while left < right:
#     s = sequence[left] + sequence[right]
#     if s == x:
#         count += 1
#         left += 1
#         right -= 1
#     elif s < x:
#         left += 1
#     else:
#         right -= 1

# print(count)

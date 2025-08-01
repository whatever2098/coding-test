import sys
input = sys.stdin.readline

MAX = 246912
# 미리 소수 여부를 구해둠
is_prime = [True] * (MAX + 1)
is_prime[0] = is_prime[1] = False

for i in range(2, int(MAX ** 0.5) + 1):
    if is_prime[i]:
        for j in range(i * i, MAX + 1, i):
            is_prime[j] = False

while True:
    num = int(input())
    if num == 0:
        break
    # num+1부터 2*num까지 소수 개수 세기
    count = sum(1 for i in range(num + 1, 2 * num + 1) if is_prime[i])
    print(count)

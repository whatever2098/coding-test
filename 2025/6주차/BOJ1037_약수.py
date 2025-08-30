import sys
input = sys.stdin.readline

n = int(input())
divisors = sorted(map(int, input().split()))
i = n // 2

if n % 2 == 0:                     # 짝수 개면 가운데 두 값 곱
    print(divisors[i - 1] * divisors[i])
else:                              # 홀수 개면 가운데 값 제곱
    print(divisors[i] * divisors[i])




'''분기가 필요없는 코드(수학원리만 알면 됨)
import sys
input = sys.stdin.readline

_ = int(input())
divisors = sorted(map(int, input().split()))
print(divisors[0] * divisors[-1])  #최솟값 * 최댓값 = N
'''
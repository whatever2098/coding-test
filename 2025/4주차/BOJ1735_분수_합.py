import sys
input = sys.stdin.readline

#분자, 분모, 분자, 분모
a1, a2, b1, b2 = map(int, input().split())

    
def GCD(high, low):
    if low == 0:
        return high
    return GCD(low, high % low)

def LCM(high, low):
    return high * low // GCD(high, low)


# 두 줄 입력 받기
a1, a2 = map(int, input().split())  # 첫 번째 분수
b1, b2 = map(int, input().split())  # 두 번째 분수

# 통분
numerator = a1 * b2 + b1 * a2
denominator = a2 * b2

# 기약분수 만들기
gcd = GCD(numerator, denominator)
numerator //= gcd
denominator //= gcd

print(numerator, denominator)





'''
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

# 분수 a/b + c/d
a, b = 1, 2
c, d = 1, 3

common = lcm(b, d)
new_a = a * (common // b)
new_c = c * (common // d)
result_num = new_a + new_c
result_den = common

print(f"{result_num}/{result_den}")  # 5/6
'''
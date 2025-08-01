import sys
input = sys.stdin.readline

def sieve(m, n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    # 에라토스테네스의 체
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    # m 이상 n 이하의 소수 출력
    for i in range(m, n + 1):
        if is_prime[i]:
            print(i)

if __name__ == "__main__":
    m, n = map(int, input().split())
    sieve(m, n)

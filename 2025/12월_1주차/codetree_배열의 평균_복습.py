import sys
input = sys.stdin.readline

arr = [list(map(int, input().split())) for _ in range(2)]

# 가로 평균
print(f"{sum(arr[0]) / 4:.1f}", end=" ")
print(f"{sum(arr[1]) / 4:.1f}")

# 세로 평균
for j in range(4):
    col_avg = (arr[0][j] + arr[1][j]) / 2
    print(f"{col_avg:.1f}", end=" ")
print()

# 전체 평균
total = sum(map(sum, arr))
print(f"{total / 8:.1f}")
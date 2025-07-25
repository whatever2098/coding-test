import sys
input = sys.stdin.read

data = input().split()

N = int(data[0])
cards = set(map(int, data[1:N+1]))

M = int(data[N+1])
queries = map(int, data[N+2:])

print(' '.join(['1' if q in cards else '0' for q in queries]))


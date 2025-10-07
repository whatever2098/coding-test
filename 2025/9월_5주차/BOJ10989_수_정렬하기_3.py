import sys
from array import array

input = sys.stdin.readline
write = sys.stdout.write

N = int(data.readline())

cnt = array('I', [0]) * 10001

for _ in range(N):
    cnt[int(data.readline())] += 1


BATCH = 10000
for num in range(1, 10001):
    c = cnt[num]
    if c:
        line = f"{num}\n".encode()
        while c >= BATCH:
            write(line * BATCH)
            c -= BATCH
        
        if c:
            write(line * c)
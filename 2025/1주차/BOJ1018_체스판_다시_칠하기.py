def repaint_count(si, sj, board):
    """
    (si, sj)를 왼쪽 위 코너로 하는 8*8 블록을 두 가지 체스 패턴과 비교하여 최소 재칠 횟수를 반환
    """
    cnt1 = 0 #기준 A: (0, 0)이 'W'
    cnt2 = 0 #기준 B: (0, 0)이 'B'
    for dx in range(8):
        for dy in range(8):
            #기대 색상 계산: (dx + dy) 짝수면 시작색, 홀수면 반대색
            expected1 = 'W' if (dx + dy) % 2 == 0 else 'B'
            expected2 = 'B' if (dx + dy) %2 == 0 else 'W'
            actual = board[si + dx][sj + dy]
            if actual != expected1:
                cnt1 += 1
            if actual != expected2:
                cnt2 += 1
    return min(cnt1, cnt2)

def main():
    import sys
    input = sys.stdin.readline
    
    n, m = map(int, input().split())
    board = [input().rstrip() for _ in range(n)]
    
    ans = float('inf')
    for i in range(n - 7):
        for j in range(m - 7):
            cnt = repaint_count(i, j, board)
            if cnt < ans:
                ans = cnt
                
    print(ans)
    
    if __name__ == "__main__":
        main()
    




'''n, m = map(int, input().split())

board_status = [False] * n * m
block = ' '  #black = true, white = false


for i in range(n):
    for j in range(m):
        if block == 'B':
            board_status[i][j] = True
        else: board_status[i][j]  = False

for board_status[i][j] in range(n):
        
    for i in range(8):
    for j in range(8):'''
        

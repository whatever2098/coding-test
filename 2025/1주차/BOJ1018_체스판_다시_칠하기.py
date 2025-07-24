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
            '''실제 색상이 패턴 A의 기대와 다르면 cnt1 증가'''
            if actual != expected1:
                cnt1 += 1
            #실제 색상이 패턴 B의 기대와 다르면 cnt2 증가   
            if actual != expected2:
                cnt2 += 1
                
            # 두 패턴 중 더 적게 칠해야 하는 경우를 반환     
    return min(cnt1, cnt2)

def main():
    import sys
    input = sys.stdin.readline  # 빠른 입력을 위해 readline 사용
    
    # n(행 수), m(열 수) 입력
    n, m = map(int, input().split())
    # 보드 정보를 문자열 리스트로 저장
    board = [input().rstrip() for _ in range(n)]
    
    ans = float('inf')  # 최소값을 찾기 위해 무한대로 초기화
    
    # 가능한 모든 8×8 블록의 시작 위치를 순회
    for i in range(n - 7):          #(0부터 n-8까지)
        for j in range(m - 7):      #(0부터 m-8까지)
            # 현재 블록의 칠해야 하는 최소 횟수 계산
            cnt = repaint_count(i, j, board)
            # 최소값 갱신
            if cnt < ans:
                ans = cnt
                
    # 결과 출력
                
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
        

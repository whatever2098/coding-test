import sys                          # 표준 입력을 빠르게 읽기 위해 sys 모듈 사용
from collections import defaultdict # 기본값 0을 갖는 카운터 용도(dict처럼 동작)
input = sys.stdin.readline          # input()을 빠른 버전으로 치환

def is_group(word: str) -> bool:    # 단어가 '그룹 단어'인지 True/False를 반환
    seen_cnt = defaultdict(int)     # 문자별로 '이전에 등장한 적이 있는가'를 기록(기본 0)
    prev = None                     # 바로 직전 문자(현재 진행 중인 블록의 문자)
    for ch in word.strip():         # 개행 제거 후, 단어를 왼쪽→오른쪽으로 한 글자씩 본다
        # '블록 경계'에서만 검사: 이전 문자와 다를 때(ch != prev)
        # 그 문자가 과거에 이미 등장(seen_cnt[ch] > 0)했다면 → 한 번 끝난 블록이 다시 시작된 것 → 그룹 단어 아님
        if ch != prev and seen_cnt[ch] > 0:
            return False
        seen_cnt[ch] += 1           # 현재 문자의 등장 기록(카운트 증가: 이후 '과거에 나왔던 문자' 판정 근거)
        prev = ch                   # 현재 문자를 '이전 문자'로 업데이트(연속 블록 추적)
    return True                     # 끝까지 위반이 없으면 그룹 단어

n = int(input().strip())            # 단어 개수 N
ans = 0                             # 그룹 단어의 개수 누적 변수
for _ in range(n):                  # N개의 단어에 대해
    if is_group(input().strip()):   # 각 단어가 그룹 단어이면
        ans += 1                    # 카운트 +1
print(ans)                          # 최종적으로 그룹 단어의 개수 출력











# 언제 뭘 쓰나? strip() / split()

# 입력 한 줄을 숫자/단어로 분리: input().split()

# 줄 끝 개행·공백만 제거: input().strip()

# 둘 다 필요(토큰화 전에 라인 정리): input().strip().split()

# CSV처럼 구분자 명확: line.split(',')

# 요약: 양끝 정리 = strip(), 토큰화 = split().
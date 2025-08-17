import sys
input = sys.stdin.readline

n = int(input())
ans = 0

while n > 0:
    word = input()
    
    block_check = [-1] * 26
    block_id = 0
    prev = None
    group = True
    count = 0
    
    
    for i in range(len(word)):
        ch = word[i]                    # 인덱스로 문자 꺼내기
        idx = ord(ch) - ord('a')
        if ch != prev:                  # 블록 경계라면
            block_id += 1
        if block_check[idx] != -1:  # 이미 다른 블록에서 등장했나?
            group = False
            break
        block_check[idx] = block_id
    prev = ch

    print("결과:", group)   # False (aabbaa는 그룹 단어 아님) ch = word[i]                    # 인덱스로 문자 꺼내기
   
    n -= 1
print(ans)

   
    
    
    
    
    
#     실행 순서(핵심 아이디어)

# 문자 하나 뽑음 → ch

# idx 계산

# 블록 경계인지 검사: if (ch != prev)

# 경계라면 block_id를 1 증가 (새 블록 시작)

# 그 문자가 예전에 다른 블록에서 이미 나왔는지 확인
# → alpha_blocks[idx] != -1 이면 끊겼다가 재등장 → 그룹 단어 아님 (ok=false, break)

# 처음 등장이라면 alpha_blocks[idx] = block_id 로 “이 문자는 지금 블록에서 등장” 기록

# prev = ch 로 직전 문자 갱신

# 루프 끝난 뒤 ok면 count++

# 포인트: 같은 문자 연속 구간(같은 블록) 에서는 아무 것도 안 하고 prev만 갱신합니다.
# 문자가 바뀌는 순간에만 “이 문자가 예전에 다른 블록에서 나왔었나?”를 검사해요.




# 🔧 네 코드에서의 문제점들

# while n > 0:
# → n을 줄이지 않아서 무한 루프. for _ in range(n)로 바꾸거나 n -= 1 필요.

# word = input()
# → 끝에 \n이 붙음. 비교 전에 **.strip()**으로 개행 제거해야 해.

# block_check = [-1:]
# → 문법 오류. 길이 26짜리 배열이 필요하니 [-1] * 26.

# prev = "\0"
# → 파이썬에선 굳이 널 문자 쓸 필요 없음. **prev = None**이 더 명확.

# for i in range(len(word)): 와 동시에 ch = 0
# → ch는 문자가 되어야 해. 인덱스 순회 말고 문자 자체를 순회하고,
# 정수 인덱스로 쓰려면 idx = ord(ch) - ord('a')가 필요.

# if block_check[ch] != -1:
# → ch는 문자라 인덱스로 못 씀. 위에서 만든 **idx**로 접근해야 함.

# break 아래에 있는 코드들
# → break 뒤 코드는 절대 실행되지 않음(unreachable).
# block_check[ch] = block_id, prev = ch, i += 1, count += 1 전부 의미 없음.

# count 변수
# → 단어별로 세려는 게 아니라 그룹 단어의 개수를 세는 게 목표라면
# 루프 밖에서 ans를 세고, 단어 끝나고 ok일 때만 ans += 1.
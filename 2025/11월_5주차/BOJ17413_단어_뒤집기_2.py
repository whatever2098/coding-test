import sys
S = sys.stdin.readline().rstrip()

in_tag = False
word = []
result = []

for c in S:
    if c == '<':
        # 태그 시작 전에 word가 비어있지 않으면 뒤집어서 출력
        if word:
            result.append(''.join(reversed(word)))
            word = []
        in_tag = True
        result.append(c)

    elif c == '>':
        in_tag = False
        result.append(c)

    elif in_tag:
        # 태그 안은 그대로 출력
        result.append(c)

    else:
        # 태그 밖
        if c == ' ':
            # 공백에서 단어 종료 → 뒤집어서 출력
            if word:
                result.append(''.join(reversed(word)))
                word = []
            result.append(' ')   # 공백 그대로 출력
        else:
            # 단어 구성 중
            word.append(c)

# 마지막 단어 처리
if word:
    result.append(''.join(reversed(word)))

print(''.join(result))

import sys
input = sys.stdin.readline

S = input().rstrip('\n')   # 마지막 개행 제거 (공백은 그대로 두기)

in_tag = False
word = []    # 태그 밖에서 현재까지 모은 글자들 (한 단어)
result = []  # 최종 결과를 쌓아둘 리스트

for c in S:
    if c == '<':
        # 태그 시작 전에, 쌓여있던 단어가 있으면 뒤집어서 결과에 넣기
        if word:
            result.extend(reversed(word))
            word = []
        in_tag = True
        result.append(c)

    elif c == '>':
        in_tag = False
        result.append(c)

    elif in_tag:
        # 태그 안에 있는 문자들은 그대로 결과에 넣기
        result.append(c)

    else:
        # 태그 밖에 있는 경우
        if c == ' ':
            # 단어가 끝났으니, 뒤집어서 결과에 넣고 공백도 넣기
            if word:
                result.extend(reversed(word))
                word = []
            result.append(c)
        else:
            # 단어 구성 중 → word에만 쌓아 두기
            word.append(c)

# 문자열 끝났는데 word에 남아있는 게 있으면 한 번 더 뒤집어서 결과에 넣기
if word:
    result.extend(reversed(word))

print(''.join(result))

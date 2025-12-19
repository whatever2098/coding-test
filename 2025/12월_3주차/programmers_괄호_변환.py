def is_correct(s):
    stack = []
    for c in s:
        if c == '(':
            stack.append(c)
        else:
            if not stack:
                return False
            stack.pop()
    return not stack


def split_uv(s):
    count = 0
    for i in range(len(s)):
        if s[i] == '(':
            count += 1
        else:
            count -= 1
        if count == 0:
            return s[:i+1], s[i+1:]


def solution(p):
    # 1. 빈 문자열
    if p == "":
        return ""

    # 2. u, v 분리
    u, v = split_uv(p)

    # 3. u가 올바른 괄호 문자열
    if is_correct(u):
        return u + solution(v)

    # 4. u가 올바르지 않은 경우
    else:
        result = "("
        result += solution(v)
        result += ")"

        # u의 첫/마지막 제거 후 뒤집기
        for c in u[1:-1]:
            if c == '(':
                result += ')'
            else:
                result += '('

        return result

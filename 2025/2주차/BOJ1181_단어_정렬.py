import sys

input = sys.stdin.read

words = input().split()[1:]  # 첫 줄은 단어 수, 나머지만 사용

unique_words = set(words)  # 중복 제거

sorted_words = sorted(unique_words, key=lambda x: (len(x), x))

print("\n".join(sorted_words))

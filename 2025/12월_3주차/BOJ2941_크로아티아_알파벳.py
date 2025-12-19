import sys
input = sys.stdin.readline

alphabets = [ 'dz=', 'c=', 'c-', 'd-', 'lj', 'nj', 's=', 'z=' ]
word = input().rstrip()

for alpha in alphabets:
    if alpha in word:
        #크로아티아 알파벳을 '*'으로 대체
        word = word.replace(alpha, '*')

'''for ch in word:
    word = word.replace(ch, '*')'''
print(len(word))

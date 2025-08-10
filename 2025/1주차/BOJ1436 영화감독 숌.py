'''666으로 끝나는 숫자들, 앞뒤에 들어가는 숫자들, 666으로 시작하는 숫자들'''

'''import sys
import itertools

def find_nth_movie(n):
    # 666부터 시작해서, 숫자에 '666'이 포함된 것만 걸러내는 제너레이터
    movies = (num for num in itertools.count(666) if '666' in str(num))
    # n번째(0-based가 아니므로 n-1) 요소를 꺼내서 반환
    return next(itertools.islice(movies, n-1, None))

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    print(find_nth_movie(n))'''
    
'''itertools.count(666)
무한히 666, 667, 668, … 을 생성하는 이터레이터를 만듭니다.

(num for num in … if '666' in str(num))
숫자를 문자열로 바꿔 '666'이 포함된 것만 걸러내는 제너레이터 표현식을 사용합니다.

itertools.islice(movies, n-1, None)
그 제너레이터에서 첫 번째(인덱스 0)가 666이므로, n번째를 얻으려면 n-1번째까지 건너뛰고 next()로 꺼냅니다.

next(...)
최종적으로 n번째 “영화”의 번호를 출력합니다.
'''


'''
전체 흐름

1부터 차례로 num을 늘려 가며 "666" 포함 여부를 보고,

포함될 때마다 count를 하나씩 올립니다.

count가 입력 n과 같아지는 순간 num을 프린트하고 함수를 종료합니다.'''

import sys

def main():
    n = int(sys.stdin.readline())
    count = 0        #나중에 n과 같은 숫자가 될때까지 증가
    num = 0          #계속 1씩 증가

    while True:
        num += 1
        if '666' in str(num):
            count += 1
            if count == n:
                print(num)
                return

if __name__ == " __main__":
    main()

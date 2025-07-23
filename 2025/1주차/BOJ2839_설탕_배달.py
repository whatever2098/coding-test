N = int(input())

# 5kg 봉지 최대 사용
five = N // 5
remain = N - five * 5

# 남은 무게가 3kg로 나눠떨어지지 않으면, 5kg 봉지 하나씩 줄여가며 반복문 없이 수식으로 처리
if remain % 3 == 0:
    print(five + remain // 3)
else:
    # 5kg 봉지 개수를 줄여가며 남은 무게가 3으로 나눠떨어지는지 확인
    # 반복문 없이 수식으로 처리: (N - 3 * k) % 5 == 0 인 k가 있는지
    k = -1
    for i in range(1, 6):
        if N - 3 * i >= 0 and (N - 3 * i) % 5 == 0:
            k = i
            break
    if k != -1:
        print((N - 3 * k) // 5 + k)
    else:
        print(-1)

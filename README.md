# coding-test

## about-coding-test-from-250712
(with 10 colleagues)  
logic-explaining practice

## 2026-1-22
BOJ1015_수열_정렬 & codetree_정렬_정렬된 수 위치
정렬과 인덱스에 관련한 문제 2개 리뷰

1. BOJ1015
2. 정렬된 수 위치

# 정렬된 수 위치 알아내기

## 문제 요약
- 수열을 오름차순 정렬했을 때  
- 각 원소가 **정렬된 배열에서 몇 번째 위치(1-based)** 인지 출력

---

## 핵심 아이디어 (한 줄)
> **정렬 후 위치(sorted_pos)를 원래 인덱스(original_idx)에 매핑한다**

---

<details>
<summary>풀이 아이디어 자세히 보기</summary>

- (값, 원래 인덱스) 형태로 저장
- 값 기준으로 정렬
- 정렬된 위치를 원래 인덱스 위치에 되돌려 저장

```cpp
P[original_idx] = sorted_pos + 1;
```
이렇게 하면
B[P[i]] = A[i] 조건을 만족한다.
</details>

<details><summary>실수하기 쉬운 포인트</summary>
  
- 출력이 **1-based인지 0-based인지** 반드시 예제로 확인
- P 벡터는 반드시 N 크기로 미리 생성
  
</details>

<details><summary>시간 복잡도</summary>
  
- 정렬: O(N log N)
- 매핑 및 출력: O(N)
- 전체:O(N log N)
  
</details>

<details><summary>C++ 코드</summary>
  
```cpp



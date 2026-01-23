## 2026-01-23
파일 생성일, 정렬 + 인덱스 문제 리뷰

# BOJ1015_수열_정렬

## 문제 요약
<details>
  <summary>문제 설명</summary>
  
- "배열 A에 적용했을 때 결과가 비내림차순이 되도록 하는
인덱스 배열 P를 찾는 문제"

- "정렬된 값을 직접 출력하지 말고,
원래 각 값이 정렬되면 몇 번째가 되는지를 출력해라"

- A[P[i]] = B[i]
</details>
---

## 핵심 아이디어
<details>
  <summary>아이디어 펼치기</summary>

1. 정렬과 인덱스 
```cpp
P[original_index] = sorted_position;
```
"이 값은 정렬하면 i번째니까
원래 자리(original_index)에 i를 쓰자."

2. 수열의 사전순
- 값이 같은 경우가 여러 개면
- 원래 인덱스가 작은 것부터 먼저 배치
- 그래야 P의 앞자리가 작아져서 사전순 최소
```cpp
1️⃣ value 오름차순
2️⃣ value 같으면 original_index 오름차순
```
</details>
---

## 구현 흐름

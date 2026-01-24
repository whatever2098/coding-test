## 2026-01-23
파일 생성일

인덱스 매핑 문제 리뷰

# BOJ1015_수열_정렬

## 문제 요약
<details>
  <summary>문제 설명</summary>
  
- "배열 A에 적용했을 때 결과가 비내림차순이 되도록 하는
인덱스 배열 P를 찾는 문제"

- "정렬된 값을 직접 출력하지 말고,
원래 각 값이 정렬되면 몇 번째가 되는지를 출력"

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
-> 비교 함수 없이 기본 sort 함수만으로 정렬 가능
</details>

---
## 구현 흐름

<details>
  <summary>핵심 두 줄</summary>

  ```cpp
  int original_idx = v[sorted_pos].first; //{index, value}로 저장돼 있는 상태
  P[original_idx] = sorted_pos;
  ```
  정렬 이후에는
  
| sorted_pos (index) | v[sorted_pos] |
|--------------------|---------------|
| 0                  | {1, 10}        |
| 1                  | {2, 20}        |
| 2                  | {3, 30}        |
| 3                  | {0, 40}        |

  - sorted_pos -> **정렬된 위치**
  - v[i].first -> **원래 인덱스**
  - i == 0 인 경우를 보면
```cpp
sorted_pos = 0
original_idx = v[0].first = 1
```
  - 정렬 후 0번째가 된 값의 원래 자리는 1번째이다.

```cpp
P[original_idx] = sorted_pos;
```
  - P[1] = 0, P[2] = 1, P[3] = 2, P[0] = 3
  - P = [3, 0, 1, 2]
  - 정렬된 위치가 원래 위치를 찾아와 매핑한다.
  
</details>

---
## 주의/실수 포인트

<details>
  <summary>포인트 펼치기</summary>
  
**0-base와 1-base 혼동**
- 문제에서 요구하는 P는 0-based
- 정렬된 첫 원소의 위치는 0
```cpp
for (int sorted_pos = 0; sorted_pos < N; sorted_pos++)
```
- ~번째라는 표현이 사용될 경우 P가 1-based일 가능성 높음
</details>

---
## 시간 복잡도

<details>
  <summary>빅오</summary>

  정렬: O(N log N)
  순회: O(N)

  전체 시간복잡도: O(N log N)
</details>

---
## C++ 코드

<details>
  <summary>코드 링크</summary>
  
  [전체 코드](BOJ1015_수열_정렬.cpp)
</details>

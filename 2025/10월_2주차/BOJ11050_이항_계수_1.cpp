#include <iostream>
#define LL long long
using namespace std;

이항 계수 문제 -> 조합 문제 -> 팩토리얼 문제 -> 재귀 문제
팩토리얼 재귀로 구현이 핵심

LL factorial(int n) {
	if (n <= 1) return 1;
	return n * factorial(n - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	//N!/K!(N-K)!
	LL fN = factorial(N);
	LL fK = factorial(K);
	LL fNK = factorial(N - K);

	cout << fN / fK / fNK << "\n";
}
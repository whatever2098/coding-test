#include <iostream>
#define LL long long
using namespace std;

static int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	LL N;
	cin >> N;
	for (LL i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr[num]++;
	}
	for (LL i = 1; i <= 10000; i++) {
		while (arr[i]--) {
			cout << i << "\n";
		}
	}
}
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int cnt1 = N;
	while (cnt1 >= 1) {
		//�Ųٷ� �� �ﰢ��
		for (int i = 0; i < cnt1; i++) {
			cout << "*";
		}
		for (int i = 0; i < cnt1 - 1; i++) {
			cout << "*";
		}
		cout << "\n";

		cnt1--;
	}
	int cnt2 = N;
	while(cnt2){
		//�ȹٷ� �� �ﰢ��
		for (int i = 0; i < N; i++) {
			cout << "*";
		}
		for (int i = 0; i < N - 1; i++) {
			cout << "*";
		}
		cout << "\n";
		cnt2--;
	}
}
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	string nums;
	cin >> nums;

    int sum{ 0 };
	for (int i{ 0 }; i < N; i++) {
		sum += (nums[i] - '0');  //char -> int
	}
	cout << sum << "\n";
}
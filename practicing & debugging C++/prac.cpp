#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int M;
	cin >> M;

	vector<char> left(s.begin(), s.end());
	vector<char> right;

	for (int i{ 0 }; i < M; i++) {

		char cmd;
		cin >> cmd;

		if (cmd == 'L') {
			if (!left.empty()) {
				right.push_back(left.back());
				left.pop_back();
			}
		}
		else if (cmd == 'D') {
			if (!right.empty()) {
				left.push_back(right.back());
				right.pop_back();
			}
		}
		else if (cmd == 'B') {
			if (!left.empty()) {
					left.pop_back();
			}
		}
		else if (cmd == 'P') {
			char x;
			cin >> x;
			left.push_back(x);

		}
	} 
	string ans;
	for (char ch : left) {
		ans += ch;
	}
	for (int i{ (int)right.size() - 1 }; i >= 0; i--) {
		ans += right[i];
	}
	cout << ans << "\n";
}

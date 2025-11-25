#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		vector<char>left, right;  //두 개의 스택처럼 사용

		for (char c : s) {
			if (c == '<') {
				if (!left.empty()) {
					right.push_back(left.back());
					left.pop_back();
				}
			}

			else if (c == '>') {
				if (!right.empty()) {
					left.push_back(right.back());
					right.pop_back();
				}
			}

			else if (c == '-') {
				if (!left.empty()) {
					left.pop_back();
				}
			}
			else {
				left.push_back(c);  //일반 문자: 커서 위치에 삽입 == 왼쪽 스택에 push
			}
		}



		//출력
		string ans;
		ans.reserve(left.size() + right.size());

			for (char c : left) { ans.push_back(c); }
			while (!right.empty()) {
				ans.push_back(right.back());
				right.pop_back();
			}

			cout << ans << "\n";
	}
}
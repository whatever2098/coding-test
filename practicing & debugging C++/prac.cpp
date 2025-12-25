#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		vector<char> left;
		vector<char> right;

		string s;
		cin >> s;

		for (int i{ 0 }; i < (int)s.size(); i++) {
			if (s[i] == '-') {
				if (!left.empty()) { left.pop_back(); }
			}
			else if (s[i] == '<') {
				if (!left.empty()) {
					right.push_back(left.back());
					left.pop_back();
				}
			}
			else if (s[i] == '>') {
				if (!right.empty()) {
					left.push_back(right.back());
					right.pop_back();
				}

			}
			else { 
				left.push_back(s[i]);
			}
		}


		string answer ="";
		for (char& c : left) {
			answer += c;
		}
		for (int i{ (int)right.size() - 1 }; i >= 0;i--) {
			answer += right[i];
		}

		cout << answer << "\n";

	}
}
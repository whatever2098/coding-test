#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string prth;
	getline(cin, prth);

	vector<char> stack;
	long long ans{ 0 };
	for (int i{ 0 }; i < prth.length(); i++) {
		if (prth[i] == '(') {
			stack.push_back(prth[i]);
		}
		else{
			stack.pop_back();

			if (prth[i - 1] == '(') {
				ans += (long long)stack.size();
			}
			else { ans += 1; }

		}
		
	}

	cout << ans;
}
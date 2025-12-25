#include <iostream>
#include <deque>	
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	deque<int> dq;
	int N, M;
	cin >> N >> M;

	for (int i{ 1 }; i <= N; i++) {
		dq.push_back(i);
	}

	int count{ 0 };
	while(M--){
		int target;
		cin >> target;
		int pos{ 0 };
		for (int i{ 0 }; i < dq.size(); i++) {
			if (dq[i] == target) { pos = i;  break; }
		}
		int left = pos;
		int sz = (int)dq.size();
		int right = (sz - pos) % sz; //pos == 0 이면 right == 0

		if (left > right) {
			count += right;
			for (int i{ 0 }; i < right; i++) {
				if (dq.empty()) break;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
		else {
			count += left;
			for (int i{ 0 }; i < left; i++) {
				if (dq.empty()) break;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		dq.pop_front();
	}
	cout << count << "\n";
}
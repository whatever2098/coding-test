#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		for (int i{ 1 }; i <= K; i++) {
			if (i != K) {
				q.push(q.front());
				q.pop();
			}
			else {
				v.push_back(q.front());
				q.pop();
			}
		}
	}
	cout << "<";
	for (int i{ 0 }; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1) { cout << ", "; }
	}
	cout << ">";
}
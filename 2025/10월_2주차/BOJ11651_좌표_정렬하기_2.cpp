#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	v.reserve(N);
	for (int i{ 0 }; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
		});

	for (int i{ 0 }; i < N; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}
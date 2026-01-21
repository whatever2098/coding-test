#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	return a.first < b.first;
}
	int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<pair<int, int>> v;  //<index, value>
	int N;
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		int num;
		cin >> num;
		v.push_back({ i, num });
	}

	sort(v.begin(), v.end(), cmp);

	for (auto e : v) {
		cout << e.first << " ";
	}
}
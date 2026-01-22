#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define value first
#define idx second
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<pair<int, int>> v;
	int N;
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		int val;
		cin >> val;
		v.push_back({ val, i });
	}

	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.value != b.value) return a.value < b.value;
		return a.idx < b.idx;
		});

	for (int sorted_idx{ 0 }; sorted_idx < N; sorted_idx++) {
		int original_idx = v[sorted_idx].idx;
		v[original_idx].idx = sorted_idx;
	}

	for (auto e : v) {
		cout << e.value << " ";
	}
}
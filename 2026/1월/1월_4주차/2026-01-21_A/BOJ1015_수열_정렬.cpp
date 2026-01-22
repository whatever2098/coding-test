#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> v;  // {index, value}
    v.reserve(N);

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back({i, num});
    }

    sort(v.begin(), v.end(), cmp);

    vector<int> P(N);
    for (int sorted_pos = 0; sorted_pos < N; sorted_pos++) {
        int original_idx = v[sorted_pos].first;
        P[original_idx] = sorted_pos;
    }

    for (int x : P) {
        cout << x << ' ';
    }
    return 0;
}

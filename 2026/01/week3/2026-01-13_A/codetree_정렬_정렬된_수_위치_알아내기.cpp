#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int,int>> v;           // (값, 원래 인덱스)
    v.reserve(N);

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        v.push_back({num, i});
    }

    // 값 오름차순, 값 같으면 원래 인덱스 오름차순(문제에서 중복 가능할 수 있어서 안전장치)
    sort(v.begin(), v.end(), [](const auto& a, const auto& b){
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    vector<int> ans(N + 1);
    for (int sorted_pos = 1; sorted_pos <= N; sorted_pos++) {
        int original_idx = v[sorted_pos - 1].second;
        ans[original_idx] = sorted_pos;
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

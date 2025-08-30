#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    long long mn = LLONG_MAX, mx = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    cout << mn * mx << '\n';
}
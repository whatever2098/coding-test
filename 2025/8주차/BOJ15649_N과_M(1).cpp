#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> path;
vector<bool> used;

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; ++i) {
            if (i) cout << ' ';
            cout << path[i];
        }
        cout << '\n';
        return;
    }
    for (int x = 1; x <= N; ++x) {
        if (!used[x]) {
            used[x] = true;
            path.push_back(x);
            dfs(depth + 1);
            path.pop_back();
            used[x] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    used.assign(N + 1, false);
    dfs(0);
    return 0;
}

#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> maps) {
    int n = (int)maps.size();
    int m = (int)maps[0].size();

    // 방문 겸 거리 배열 (0이면 아직 안 감)
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<int,int>> Q;

    // 시작점이 벽이면 바로 -1 (안전)
    if (maps[0][0] == 0) return -1;

    dist[0][0] = 1;
    Q.push({0, 0});

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (maps[nx][ny] == 0) continue;      // 벽
            if (dist[nx][ny] != 0) continue;      // 이미 방문

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    int ans = dist[n-1][m-1];
    if (ans == 0) return -1;
    return ans;
}

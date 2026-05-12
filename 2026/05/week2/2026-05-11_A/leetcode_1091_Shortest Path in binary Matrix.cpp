#include <vector>
#include <queue>
#include <tuple>
using namespace std;

//큐에 거리까지 같이 넣기
class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int n = grid.size();

		int dx[8] = { 0, 1, 1, 1, 0, -1, -1, - 1 }; // 오른쪽부터 시계방향으로
		int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

		if (grid[0][0] == 1) return -1;
		if (grid[n - 1][n - 1] == 1) return -1;

		queue<tuple<int, int, int>> q; // {x, y, dist}

		q.push({ 0, 0, 1 });
		grid[0][0] = 1;

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			int x = get<0>(cur);
			int y = get<1>(cur);
			int dist = get<2>(cur);

			if (x == n - 1 && y == n - 1) return dist;

			for (int dir{ 0 }; dir < 8; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (grid[nx][ny] == 1) continue;
				
				grid[nx][ny] = 1;
				q.push({ nx, ny, dist + 1});
			}
		}
		return -1;
	}
};


//BFS 레벨 단위로 거리 세기
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1) return -1;
        if (grid[n - 1][n - 1] == 1) return -1;

        int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
        int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        grid[0][0] = 1;

        int dist = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (x == n - 1 && y == n - 1) {
                    return dist;
                }

                for (int dir = 0; dir < 8; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (grid[nx][ny] == 1) continue;

                    grid[nx][ny] = 1;
                    q.push({ nx, ny });
                }
            }

            dist++;
        }

        return -1;
    }
};
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int n = grid.size();
		int m = grid[0].size();

		vector<vector<bool>> visited(n, vector<bool>(m, false));
		queue<pair<int, int>> q;

		int dx[4] = { 1, 0, -1, 0 };
		int dy[4] = { 0, -1, 0, 1 };

		int cntLand{ 0 };

		for (int i{ 0 }; i < n; i++) {
			for (int j{ 0 }; j < m; j++) {
				if (grid[i][j] == '0' || visited[i][j] == true) continue;
				
				cntLand++;

				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int dir{ 0 }; dir < 4; dir++) {
						int new_x = x + dx[dir];
						int new_y = y + dy[dir];

						if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
						if (grid[new_x][new_y] == '0') continue;
						if (visited[new_x][new_y]) continue;

						visited[new_x][new_y] = true;
						q.push({ new_x, new_y });
					}
				}
			}
		}

		return cntLand;
	}
};
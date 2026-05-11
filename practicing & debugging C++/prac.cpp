#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();

		int dx[4] = { 1, 0, -1, 0 };//0123
		int dy[4] = { 0, -1, 0, 1 };//오아왼위

		int minute{ 0 };
		int fresh{ 0 };

		queue<pair<int, int>> q;

		for (int i{ 0 }; i < n; i++) {
			for (int j{ 0 }; j < m; j++) {
				if (grid[i][j] == 1) fresh++;
				else if (grid[i][j] == 2) q.push({ i, j });
			}
		}
		int rotted = q.size();
		while (!q.empty() && fresh) {
			while (rotted--) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int dir{ 0 }; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (grid[nx][ny] != 1) continue;

					grid[nx][ny] = 2;
					fresh--;
					q.push({ nx, ny });
				}
				minute++;
			}
		}
		return ((fresh) ? -1 : minute);
	}
};
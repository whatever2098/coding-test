#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();

		int dx[4] = { 1, 0, -1, 0 };
		int dy[4] = { 0, -1, 0, 1 };

		int minute{ 0 };
		queue<pair<int, int>> q;
		int fresh{ 0 };
		
		// 처음 썩은 오렌지는 큐에 넣는다.
		for (int i{ 0 }; i < n; i++) {
			for (int j{ 0 }; j < m; j++) {
				if (grid[i][j] == 2) {
					q.push({ i, j });
				}
				else if (grid[i][j] == 1) {
					fresh++;
				}
			}
		}

		if (fresh == 0) return 0;

		while (!q.empty()) {

			int size = q.size();
			bool rotted = false;

			for (int i{ 0 }; i < size; i++) {
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
					rotted = true;
					q.push({ nx, ny });
				}
			}
			if(rotted) minute++;
		}

		return fresh == 0 ? minute : -1;
		
	}
};
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int n = grid.size();

		int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
		int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }; //위부터 시계 방향으로

		queue<tuple<int, int, int>> q; //x, y, dist

		int x{ 0 };
		int y{ 0 };
		int dist{ 0 };
		if(grid[x][y] != 1){ q.push({ 0, 0, 0 }); }
		grid[x][y] = 1;  //visited

		while (!q.empty()) {
			if (x == n - 1 && y == n - 1) { return dist; }
			auto cur = q.front();
			x = get<0>(cur);
			y = get<1>(cur);
			dist = get<2>(cur);
			q.pop();

			for (int dir{ 0 }; dir < 8; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				
				if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 1) continue;
				q.push({ nx, ny, dist++ });
			}
		}
		return -1;

	}
};

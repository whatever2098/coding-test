#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(vector<vector<int>> maps) {
	int n = maps.size();
	int m = maps[0].size();

	queue<pair<int, int>> q;
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i{ 0 }; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
			if (maps[new_x][new_y] == 0) continue;
			if (visited[new_x][new_y] == true) continue;

			visited[new_x][new_y] = true;
			maps[new_x][new_y] = maps[x][y] + 1;
			q.push({ new_x, new_y });
		}
	}

	if (!visited[n - 1][m - 1]) { return -1; }
	return maps[n - 1][m - 1];
}
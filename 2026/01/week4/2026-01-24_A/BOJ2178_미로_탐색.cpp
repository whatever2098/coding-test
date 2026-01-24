#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int board[101][101];
	int dist[101][101] = { 0 };

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	int N, M;
	cin >> N >> M;

	for (int i{ 1 }; i <= N; i++) {
		string s;
		cin >> s;
		for (int j{ 1 }; j <= M; j++) {
			board[i][j] = s[j - 1] - '0'; //char -> int로 변환
		}
		
	}

	queue<pair<int, int>> q;
	dist[1][1] = 1;
	q.push({ 1, 1 });

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		
		for (int dir{ 0 }; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
			if (dist[nx][ny] != 0) continue;
			if (board[nx][ny] == 0) continue;

			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}

	cout << dist[N][M] << "\n";
}
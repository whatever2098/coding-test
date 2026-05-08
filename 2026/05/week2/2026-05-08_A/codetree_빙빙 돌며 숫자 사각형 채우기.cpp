#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M, 0));

    // 오른쪽, 아래쪽, 왼쪽, 위쪽
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };

    int x = 0; // 행
    int y = 0; // 열
    int dir = 0; // 처음 방향: 오른쪽
    int number = 1;

    while (number <= N * M) {
        grid[x][y] = number;
        number++;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M || grid[nx][ny] != 0) {
            dir = (dir + 1) % 4;

            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
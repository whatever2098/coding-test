#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<char>> grid(N, vector<char>(M, ' '));
    int alphabet = 'A';
    
    int dx[4] = { 0, 1, 0, -1 }; //0123
    int dy[4] = { 1, 0, -1, 0 }; //오아왼위

    int x{ 0 };
    int y{ 0 };
    grid[x][y] = alphabet;
    int dir{ 0 };
    int cnt{ 1 };
    while (M * N > cnt) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M || grid[nx][ny] != ' ') {
            dir = (dir + 1) % 4; continue;
        }

        x = nx;
        y = ny;
        alphabet++;
        if (alphabet > 'Z') { alphabet = 'A'; }
        grid[x][y] = (char)alphabet;
        cnt++;
    }

    for (int i{ 0 }; i < N; i++) {
        for (int j{ 0 }; j < M; j++) {
            cout << (char)grid[i][j] << " ";
        }
        cout << "\n";
    }
}
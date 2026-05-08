#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int x{ 0 };
	int y{ 0 };

	int dx[4] = { -1, 0, 0, 1 }; //0, 1, 2, 3
	int dy[4] = { 0, -1, 1, 0 }; //W, S, N, E

	int N;
	cin >> N;
	int cnt_t{ 0 };
	int dir{ 0 };

	for (int i{ 0 }; i < N; i++) {
		char input_dir;
		int dist;
		cin >> input_dir >> dist;

		if (input_dir == 'W') dir = 0;
		else if (input_dir == 'S')dir = 1;
		else if (input_dir == 'N') dir = 2;
		else if (input_dir == 'E') dir = 3;

		for (int j{ 0 }; j < dist; j++) {
			x += dx[dir];
			y += dy[dir];
			cnt_t++;

			if (x == 0 && y == 0) {
				cout << cnt_t << "\n";
				return 0;
			}
		}
	}
	cout << -1 << "\n";
}
/*
이동 거리 dist만큼, 현재 방향으로 한 칸씩 이동한다. 한 칸 이동할 때마다 시간이 1초 증가한다.
즉, 한 칸 이동 -> 시간 증가 -> 원점인지 확인 순서이다.
*/
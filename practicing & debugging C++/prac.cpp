#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, T;
	cin >> N >> T;


	int dx[4] = { 1, -1, 0, 0 };  //행x과 열y 이라는 걸 잊지 말자.
	int dy[4] = { 0, 0,  1, -1 }; //U, D, R, L
	int R, C;
	char D;
	cin >> R >> C >> D;
	int x = R - 1;
	int y = C - 1;

	while (T--) {
		int dir;
		
		if (D == 'U') dir = 0;
		else if (D == 'D') dir = 1;
		else if (D == 'R') dir = 2;
		else { dir = 3; }

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
			if (D == 'U') { D = 'D'; }
			else if (D == 'D') { D = 'U'; }
			else if (D == 'R') { D = 'L'; }
			else { D = 'R'; }
		}
		else {
			x = nx;
			y = ny;
		}

	}
	cout << x + 1 << " " << y + 1 << "\n";
	return 0;
}
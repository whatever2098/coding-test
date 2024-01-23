#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int status;
	for (int i{ 0 }; i < 3; i++) {
		status = 0;
		for (int j{ 0 }; j < 4; j++) {
			bool yoot;
			cin >> yoot;
			status += yoot;
		}

		switch (status) {
		case 0: cout << 'D';
			break;
		case 1: cout << 'C';
			break;
		case 2: cout << 'B';
			break;
		case 3: cout << 'A';
			break;
		case 4: cout << 'E';
			break;
		}
		cout << "\n";
	}
}
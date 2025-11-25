#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string line;
	getline(cin, line);

	int cnt{ 0 };
	for (int i{ 0 }; i < line.size(); i++) {
		if (line[i] != ' ') cnt++;
		while (i < line.size() && line[i] != ' ') i++;
	}

	cout << cnt << "\n";
}
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string source;

	while (getline(cin, source)) {
		while (true) {
			size_t pos = source.find("BUG");
			if (pos == string::npos) break;
			source.erase(pos, 3);
		}
		cout << source << "\n";
	}
}

//find()가 실패하면 string::npos가 나온다
//string::npos는 size_t의 최대값이다
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	int cnt{ 0 };
	string num{ "666" };
	while (cnt < N) {
		for (int i{ 0 }; i < num.length(); i++) {
			if (num[i] == '6' && num[i + 1] == '6' && num[i + 2] == '6') { cnt++; break; }
		}
		num = to_string(stoi(num) + 1);
	}
	cout << stoi(num) - 1 << "\n";
}


/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int count = 0;
    int num = 665;  // 첫 번째로 검사할 때 ++ 연산 후 666부터 시작되도록

    while (count < N) {
        num++;
        // to_string으로 변환 후 "666" 포함 여부 검사
        if (to_string(num).find("666") != string::npos) {
            count++;
        }
    }

    cout << num << "\n";
    return 0;
}

*/
#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	deque<int> dq;
	for (int i{ 1 }; i <= N; i++) {
		dq.push_back(i);
	}

	int count{ 0 };

	while (M--) {
        //idx의 위치 찾기
        //왼쪽으로 돌리는 게 빠른지 오른쪽으로 돌리는 게 빠른지 판단
		int idx;
		cin >> idx;
		int left{ 0 }, right{ 0 };
		for (int i{ 0 }; i < dq.size(); i++) {
			if (idx == dq[i]) {
				left = i;
				right = dq.size() - left;
				break;
			}
		}

        //더 작은 쪽으로 회전
        //왼쪽이 더 작을 때
		if (left <= right) {
			while (left--) {
				dq.push_back(dq.front());
				dq.pop_front();
				count++;
			}
		}
        //오른쪽이 더 작을 때
		else {
			while (right--) {
				dq.push_front(dq.back());
				dq.pop_back();
				count++;
			}
		}
		dq.pop_front();
	}
	cout << count << "\n";
}

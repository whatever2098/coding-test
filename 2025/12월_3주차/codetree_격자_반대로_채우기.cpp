#include <iostream>
using namespace std;

int main() {
    int arr[11][11] = {0};
    int N;
    cin >> N;

    int num = 1;

    for (int j = N - 1; j >= 0; j--) {
        int k = (N - 1 - j);          // 오른쪽에서부터의 오프셋(0,1,2,...)

        if (k % 2 == 0) {             // 0번째(오른쪽 끝), 2번째, ... : 아래 -> 위
            for (int i = N - 1; i >= 0; i--) {
                arr[i][j] = num++;
            }
        } else {                       // 1번째, 3번째, ... : 위 -> 아래
            for (int i = 0; i < N; i++) {
                arr[i][j] = num++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << arr[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}

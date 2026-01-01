#include <iostream>
#include <deque>
#include <cctype>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string p, arrStr;
        int n;
        cin >> p >> n >> arrStr;

        deque<int> dq;

        // "[1,2,3]" 파싱
        int num = 0;
        bool inNum = false;
        for (char ch : arrStr) {
            if (isdigit((unsigned char)ch)) {
                num = num * 10 + (ch - '0');
                inNum = true;
            } else {
                if (inNum) {
                    dq.push_back(num);
                    num = 0;
                    inNum = false;
                }
            }
        }

        bool reversed = false;   // 이것 하나만 사용!
        bool error = false;

        for (char c : p) {
            if (c == 'R') {
                reversed = !reversed;
            } else if (c == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (!reversed) dq.pop_front();
                else dq.pop_back();
            }
        }

        if (error) {
            cout << "error\n";
            continue;
        }

        // 출력
        cout << '[';
        if (!dq.empty()) {
            if (!reversed) {
                for (int i = 0; i < (int)dq.size(); i++) {
                    if (i) cout << ',';
                    cout << dq[i];
                }
            } else {
                for (int i = (int)dq.size() - 1; i >= 0; i--) {
                    if (i != (int)dq.size() - 1) cout << ',';
                    cout << dq[i];
                }
            }
        }
        cout << "]\n";
    }
    return 0;
}

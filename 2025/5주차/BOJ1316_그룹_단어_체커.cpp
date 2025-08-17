#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int count = 0;

    while (n--) {
        string w; cin >> w;
        vector<int> alpha_blocks(26, -1);
        int block_id = 0;
        char prev = '\0';
        bool ok = true;

        for (char ch : w) {
            int idx = ch - 'a';
            if (ch != prev) {
                block_id++;
                if (alpha_blocks[idx] != -1) {
                    ok = false;
                    break;
                }
                alpha_blocks[idx] = block_id;
            }
            prev = ch;
        }

        if (ok) count++;
    }

    cout << count << "\n";
}





// 변수 뜻

// w: 현재 단어

// prev: 직전 문자(초기 '\0' 등). 문자 블록이 바뀌는 순간을 잡는 데 사용

// idx = ch - 'a': 문자 ch를 0~25 정수 인덱스로(‘a’→0 … ‘z’→25)

// alpha_blocks[26]: 각 알파벳이 마지막으로 등장했던 블록 번호를 저장 (-1이면 아직 안 나옴)

// block_id: 문자 블록 번호. 문자가 바뀔 때마다 1 증가

// ok: 이 단어가 그룹 단어인지 여부

// 실행 순서(핵심 아이디어)

// 문자 하나 뽑음 → ch

// idx 계산

// 블록 경계인지 검사: if (ch != prev)

// 경계라면 block_id를 1 증가 (새 블록 시작)

// 그 문자가 예전에 다른 블록에서 이미 나왔는지 확인
// → alpha_blocks[idx] != -1 이면 끊겼다가 재등장 → 그룹 단어 아님 (ok=false, break)

// 처음 등장이라면 alpha_blocks[idx] = block_id 로 “이 문자는 지금 블록에서 등장” 기록

// prev = ch 로 직전 문자 갱신

// 루프 끝난 뒤 ok면 count++

// 포인트: 같은 문자 연속 구간(같은 블록) 에서는 아무 것도 안 하고 prev만 갱신합니다.
// 문자가 바뀌는 순간에만 “이 문자가 예전에 다른 블록에서 나왔었나?”를 검사해요.
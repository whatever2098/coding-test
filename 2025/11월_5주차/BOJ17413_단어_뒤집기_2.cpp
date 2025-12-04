#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    // 공백 포함해서 한 줄 전체 입력
    getline(cin, S);

    string word;   // 태그 밖에서 단어를 임시로 저장
    string result; // 최종 결과를 쌓을 문자열
    bool inTag = false; // 지금 태그 안에 있는지 여부

    for (char c : S) {
        if (c == '<') {
            // 태그 시작 전에 버퍼에 쌓인 단어가 있으면 뒤집어서 추가
            if (!word.empty()) {
                reverse(word.begin(), word.end());
                result += word;
                word.clear();
            }
            inTag = true;
            result += c; // '<' 까지 그대로 추가
        }
        else if (c == '>') {
            inTag = false;
            result += c; // '>' 도 그대로 추가
        }
        else if (inTag) {
            // 태그 안에서는 어떤 문자든 그대로 추가
            result += c;
        }
        else {
            // 태그 밖의 문자 처리
            if (c == ' ') {
                // 단어 종료 → 뒤집어서 추가
                if (!word.empty()) {
                    reverse(word.begin(), word.end());
                    result += word;
                    word.clear();
                }
                result += c; // 공백 그대로
            } else {
                // 단어 구성 중인 문자
                word += c;
            }
        }
    }

    // 문자열이 끝났을 때, 마지막 단어가 남아 있을 수 있음
    if (!word.empty()) {
        reverse(word.begin(), word.end());
        result += word;
    }

    cout << result << '\n';
    return 0;
}

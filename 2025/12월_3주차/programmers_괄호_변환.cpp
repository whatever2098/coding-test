#include <bits/stdc++.h>
using namespace std;

// 올바른 괄호 문자열인지 체크
bool isCorrect(const string& s) {
    int bal = 0;
    for (char c : s) {
        if (c == '(') bal++;
        else bal--;
        if (bal < 0) return false; // ')'가 먼저 많아지면 틀림
    }
    return bal == 0;
}

// p를 가장 작은 균형잡힌 접두사 u와 나머지 v로 분리
pair<string,string> splitUV(const string& p) {
    int bal = 0;
    for (int i = 0; i < (int)p.size(); i++) {
        if (p[i] == '(') bal++;
        else bal--;
        if (bal == 0) { // 여기까지가 가장 작은 균형 접두사
            return {p.substr(0, i + 1), p.substr(i + 1)};
        }
    }
    return {p, ""}; // 이론상 여기 올 일 거의 없음(입력이 균형잡힌 문자열이라면)
}

string solve(const string& p) {
    if (p.empty()) return "";

    auto [u, v] = splitUV(p);

    if (isCorrect(u)) {
        // 3. u가 올바르면 u + solve(v)
        return u + solve(v);
    }

    // 4. u가 올바르지 않으면:
    // "(" + solve(v) + ")" + (u의 첫/끝 제거 후 괄호 뒤집기)
    string res = "(" + solve(v) + ")";

    string mid = u.substr(1, u.size() - 2); // u[1..len-2]
    for (char &c : mid) {
        c = (c == '(' ? ')' : '('); // 뒤집기
    }
    res += mid;
    return res;
}

string solution(string p) {
    return solve(p);
}

#include <string>
#include <vector>
using namespace std;

bool isCorrect(const string& s) {
    vector<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push_back(c);
        } 
        else {
            if (st.empty()) return false;

            char top = st.bsack();
            st.pop_back();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }
    return st.empty();
}

int solution(strsing s) {
    int answer = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (isCorrect(s)) answer++;
        s = s.substr(1) + s[0]; // 회전
    }

    return answer;
}

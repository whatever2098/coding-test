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
		        //✅ “스택이 비었다” = “닫을 게 없다” = “닫는 괄호가 먼저 나왔다” → 무조건 틀림
            if (st.empty()) return false;
            
            char top = st.back();
            st.pop_back();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (isCorrect(s)) answer++;
        s = s.substr(1) + s[0]; // 회전
    }

    return answer;
}

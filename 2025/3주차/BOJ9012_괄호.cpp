#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string parentheses;
        cin >> parentheses;
        stack<char> check; // 스택은 char로 선언
        bool isValid = true; // 올바른 괄호 여부

        for (char c : parentheses) { // 문자열의 각 문자에 대해
            if (c == '(') {
                check.push(c); // 여는 괄호는 스택에 push
            } else if (c == ')') {
                if (check.empty()) { // 스택이 비어있으면 짝이 안 맞음
                    isValid = false;
                    break;
                }
                check.pop(); // 닫는 괄호는 스택에서 pop
            }
        }
        if (!check.empty()) isValid = false; // 스택이 남아있으면 올바르지 않음
        cout << (isValid ? "YES" : "NO") << '\n'; // 결과 출력
    }
}

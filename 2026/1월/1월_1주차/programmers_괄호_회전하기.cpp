#include <iostream>
#include <vector>
using namespace std;

bool isCorrect(const string& s){
    vector<char> st;
    st.reserve(s.size());

    for (char c : s){
        if(c == '(' || c == '{' || c == '['){
            st.push_back(c);
        }else {
            if(st.empty()) return false;
        
            char top = st.back();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')){
                    return false;
            }
            st.pop_back();
        }
    }
    return st.empty();
}

int solution(string p){
    
    int n = (int)p.size();
    int xCnt{0};

    for(int i{0};i < n;i++){
        if(isCorrect(p)){
            xCnt++;
        }
        p = p.substr(1) + p[0];
        
    }
    return xCnt;
}
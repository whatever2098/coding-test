#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int sum{0};

int recursion(const char *s, int l, int r){
    sum++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, static_cast<int>(strlen(s)) - 1);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        string S;
        cin >> S;
        cout << isPalindrome(S.c_str()) << " ";
        cout << sum << "\n";
        sum = 0;
    }

}
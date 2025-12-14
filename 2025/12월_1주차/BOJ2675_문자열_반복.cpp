#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int R;
        string S;
        cin >> R >> S;
        for(char c : S){
            for(int i{0};i < R;i++){
                cout << c;
            }
        }
        cout << "\n";
    }
}
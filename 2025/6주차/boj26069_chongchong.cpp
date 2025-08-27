#include <iostream>
#include <set>
using namespace std;

set<string> s;

int main(){
    int n;
    cin >> n;
    s.insert("ChongChong");

    for(int i{0}; i < n;i++){
        string a, b;
        cin >> a >> b;

        if(s.find(a) != s.end() || 
        s.find(b) != s.end()){
            s.insert(a);
            s.insert(b);
        }
    }

    
    cout << s.size() << "\n";

}
#include <iostream>
#include <set>
using namespace std;


set<int> s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N;
    for(int i { 0 };i < N;i++){
        int num;
        cin >> num;
        s.insert(num);
    }

    cin >> M;
    for(int i {0};i < M;i++){
        int num_chk;
        cin >> num_chk;
        
        cout << ((s.find(num_chk) == s.end())? 0 : 1) << " ";
    }
}
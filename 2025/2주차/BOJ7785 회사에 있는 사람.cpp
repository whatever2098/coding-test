#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> um;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for(int i { 0 }; i < n;i++){
        string name;
        string ent_or_lea;
        cin >> name >> ent_or_lea;

        if( ent_or_lea == "enter"){
            um[name] = true; continue;
        }   
        um[name] = false;
    }
    
    // 사무실에 남아 있는 사람만 골라서 벡터에 담고
    vector<string> ans;
    ans.reserve(um.size());  //reserve 성능 개선용(많은 할당, 복사 없어짐)
    for (auto& [name, here] : um) {
        if (here) 
            ans.push_back(name);
    }

    // 사전 내림차순으로 정렬
    sort(ans.begin(), ans.end(), greater<string>());

    // 출력
    for (auto& s : ans) {
        cout << s << '\n';
    }

    return 0;
}
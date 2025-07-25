#include <iostream>
#include <algorithm>
#include <string>
#include <utility>   //pair를 쓰기 위해
#include <vector>
using namespace std;

vector<pair<int, string>> v;

bool compare(const pair<int, string>& a, const pair<int, string>& b){
    if (a.first != b.first){
        return a.first < b.first;
    return a.second < b.second;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    v.reserve(N);

    for(int i{0};i < N;i++){
        string input;
        cin >> input;
        v.emplace_back(input.length(), input);
    }


    sort(v.begin(), v.end(), compare);


    //단 중복된 단어는 하나만 남기고 제거해야 한다.
// 새 벡터에 중복 없이 옮기기
vector<pair<int, string>> uniq;
uniq.reserve(v.size());  // 대략 크기만큼 메모리 확보

string prev = "";  
for (const auto& p : v) {
    if (p.second != prev) {
        uniq.push_back(p);
        prev = p.second;
    }
}

// 원본 v를 교체
v = move(uniq);
 for (const auto& e : v) {
     cout << e.second << "\n;
 }

}
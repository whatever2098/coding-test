#include <iostream>
using namespace std;

vector<pair<int, int>> v;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(nullptr); cout.tie(nullptr);

int N;
cin >> N;

for(int i = 0; i < N;i++){
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
}
sort(v.begin(), v.end());
for(int i = 0;i < N;i++){
    cout << v[i].first << " " << v[i].second << "\n";
}

}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     int N;
//     cin >> N;

//     vector<pair<int, int>> v(N); // N개의 (x, y) 쌍

//     for (auto& p : v)
//         cin >> p.first >> p.second;

//     sort(v.begin(), v.end()); // x 오름차순, 같으면 y 오름차순 정렬

//     for (auto& p : v)
//         cout << p.first << " " << p.second << "\n";
// }

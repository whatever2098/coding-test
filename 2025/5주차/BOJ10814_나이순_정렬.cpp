#01
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Person {
    int age;
    int idx;      // 입력된 순서
    string name;
};

bool cmp(const Person& a, const Person& b) {
    if (a.age != b.age) return a.age < b.age; // 나이 오름차순
    return a.idx < b.idx;                     // 같은 나이면 입력 순서 유지
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    vector<Person> v;
    v.reserve(N);

    for (int i = 0; i < N; ++i) {
        int age; string name;
        cin >> age >> name;
        v.push_back({age, i, name});
    }

    sort(v.begin(), v.end(), cmp);

    for (const auto& p : v) {
        cout << p.age << ' ' << p.name << '\n';
    }
    return 0;
}




#02 튜플 이용한 sort 방법 
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<tuple<int,int,string>> a; // (age, idx, name)
    a.reserve(N);

    for (int i = 0; i < N; ++i) {
        int age; string name;
        cin >> age >> name;
        a.emplace_back(age, i, name);
    }

    sort(a.begin(), a.end(),
        [](const auto& x, const auto& y){
            if (get<0>(x) != get<0>(y)) return get<0>(x) < get<0>(y); // age
            return get<1>(x) < get<1>(y); // idx(입력 순서)
        });

    for (const auto& [age, idx, name] : a) {
        cout << age << ' ' << name << '\n';
    }
}



#03튜플 + 람다
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<tuple<int,int,string>> a; // (age, idx, name)
    a.reserve(N);
    for (int i = 0; i < N; ++i) {
        int age; string name;
        cin >> age >> name;
        a.emplace_back(age, i, name);
    }

    sort(a.begin(), a.end(),
        [](const auto& x, const auto& y){
            if (get<0>(x) != get<0>(y)) return get<0>(x) < get<0>(y); // age
            return get<1>(x) < get<1>(y);                             // idx
        });

    for (auto& [age, idx, name] : a) {
        cout << age << ' ' << name << '\n';
    }
}




#C++17 스타일 (구조적 바인딩)
sort(a.begin(), a.end(),
    [](const auto& lhs, const auto& rhs){
        const auto& [age1, idx1, name1] = lhs;
        const auto& [age2, idx2, name2] = rhs;
        return (age1 != age2) ? (age1 < age2) : (idx1 < idx2);
    });

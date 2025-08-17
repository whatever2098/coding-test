#include <iostream>
#include <vector>
using namespace std;

vector<long long> v(0);  //지워지지 않는 벡터
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    long long K;
    cin >> K;
    for(long long i{ 0 };i < K;i++){
        long long sample;
        cin >> sample;

       if(sample == 0 && !v.empty()){
            v.pop_back();
            continue;
       }
       v.push_back(sample);
    }

    long long sum{ 0 };
    for (long long i{0};i < v.size();i++){
        sum += v[i];
    }

    cout << sum << "\n";
}
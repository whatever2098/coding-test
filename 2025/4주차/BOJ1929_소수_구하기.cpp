#include <iostream>
using namespace std;

bool isPrime(int num){
    if(num < 2) return false;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m, n;
    cin >> m >> n;
    for(int i = m; i <= n; i++){
        if(isPrime(i)){
            cout << i << "\n";
        }
    }
    return 0;
}  









/*
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);  // C의 stdio와 동기화를 끊어 cin/cout 속도 향상
    cin.tie(0);                   // cin과 cout의 묶음을 풀어 속도 향상

    int m, n;
    cin >> m >> n;

    // 0부터 n까지 소수인지 여부를 저장할 배열 (처음엔 모두 true)
    vector<bool> is_prime(n + 1, true);

    // 0과 1은 소수가 아니므로 false로 설정
    is_prime[0] = false;
    is_prime[1] = false;

    // 2부터 sqrt(n)까지 반복
    for(int i = 2; i * i <= n; i++){
        if(is_prime[i]){
            // i가 소수면, i의 배수는 소수가 아님 → 전부 제거 (false)
            for(int j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }

    // 이제 m 이상 n 이하의 소수만 출력
    for(int i = m; i <= n; i++){
        if(is_prime[i]){
            cout << i << "\n";
        }
    }

    return 0;
}

*/
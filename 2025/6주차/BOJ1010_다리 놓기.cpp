#include <iostream>
using namespace std;

int main(){
    iosbase::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    int N, M;
    cin >> N >> M;

    //동쪽의 지점을 오름차순으로 N개 선택 조합문제
    //서쪽 N개를 고정하고 동쪽에서 N개를 고르는 셈
    /*방법 1: 파스칼 삼각형 DP
     
    1≤N≤M≤30 정도라서 값이 작음 → 정수 범위(int/long long) 내에서 안전.

    C[n][k] = C[n - 1][k - 1] + C[n - 1][k],
    C[n][0] = C[n][n] = 1로 미리 최대 30까지 채움->각 테스트는 O(1).
    


    */





}
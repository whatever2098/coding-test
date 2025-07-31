#include <iostream>
using namespace std;


int GCD(int a, int b){
    while(b != 0){
        int temp = a % b;
        a = b;
        b = temp;
    }
   return a;
}

int LCM(int a, int b){
    return a * b / GCD(a, b);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        int A, B;
        cin >> A >> B;
        cout << LCM(A, B) << "\n";
    }

}


/*2. LCM 함수의 GCD 계산 후 원래 값 손실
유클리드 호제법으로 GCD를 구할 때, a와 b의 원래 값을 보존해야 합니다.
현재는 a와 b가 GCD 계산 과정에서 바뀌므로, LCM 계산에 사용할 수 없습니다.*/
/*LCM 계산식과 GCD 계산을 분리해야 하며, 원래의 a, b 값을 보존해야 합니다.*/
#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int total5 { 0 }; // 5kg 봉지 개수
    int total3 { 0 }; // 3kg 봉지 개수
    int total { -1 }; // 최소 봉지 개수, 기본값 -1

    // 5kg 봉지를 최대한 많이 쓰는 것부터 시도
    for(int i { N / 5 }; i >= 0; i--){
        int remain = N - i * 5; // 5kg 봉지로 뺀 나머지 무게
        if(remain % 3 == 0){ // 남은 무게가 3kg로 나눠떨어지면
            total5 = i;
            total3 = remain / 3;
            total = total5 + total3; // 봉지 개수 합
            break; // 최소 개수 찾았으니 종료
        }
    }
    cout << total; // 결과 출력 (정확히 안 나눠지면 -1)
}
#include <iostream>
#include <iomanip>
using namespace std;

int arr[2][4] = {};   //전역 배열 0으로 초기화
int main(){
    double whole{0};
    for(int i{0};i < 2;i++){
        for(int j{0};j < 4;j++){
            cin >> arr[i][j];
            whole += arr[i][j];
        }
    }

     // 출력 형식: 소수 첫째 자리까지
    cout << fixed << setprecision(1);
    
    //가로 평균 2개
    int sum {0};
    for(int t : arr[0]){
        sum += t;
    }
    cout<< (static_cast<double>(sum) / 4) << " ";
    
    sum = 0;
    for(int t : arr[1]){
        sum += t;
    }
    cout<< (static_cast<double>(sum) / 4) << "\n";

    //세로 평균 4개
    for(int j{0};j < 4;j++){
       cout << (static_cast<double>( arr[0][j] + arr[1][j] ) / 2) << " ";
    }
    cout << "\n";

    //전체 평균
    cout << (whole / 8) <<"\n";

}
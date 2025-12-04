#include <iostream>
#include <vector>
#include <iomanip>   //setprecision
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int arr[2][4];
    for(int i{0};i < 2;i++){
        for(int j{0};j < 4;j++){
            cin >> arr[i][j];
        }
    }

    int sum1 = 0;
    int sum2 = 0;
    for (int j{0}; j < 4;j++){
        sum1 += arr[0][j];
        sum2 += arr[1][j];
    }
    double row_avg1 = sum1 / 4.0;  //정수 나눗셈 -> 소수점 날아감   
    double row_avg2 = sum2 / 4.0;  //또는 static_cast<double>(sum2)도 가능

    vector<double> col_avg(4);
    for( int j{0}; j < 4;j++){
        col_avg[j] = (arr[0][j] + arr[1][j]) / 2.0;
    }

    double total_avg = (sum1 + sum2) / 8.0;


    //출력 소수 첫째자리
    cout << fixed << setprecision(1);
    cout << row_avg1 << " " << row_avg2 << "\n";
    for(auto e : col_avg){
        cout << e << " ";
    }
    cout << "\n";
    cout << total_avg << "\n";
    return 0;
}
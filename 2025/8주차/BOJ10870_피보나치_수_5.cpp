#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int fib[21];
    fib[0] = 0;
    fib[1] = 1;

    for(int i{2};i <= n;i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << fib[n] << "\n";
}
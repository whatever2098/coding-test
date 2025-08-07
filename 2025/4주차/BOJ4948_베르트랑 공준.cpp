#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 246912;  //123456의 2배

bool isPrime[MAX + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fill_n(isPrime, MAX + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        int count = 0;
        for (int i = n + 1; i <= 2 * n; ++i) {
            if (isPrime[i]) ++count;
        }

        cout << count << "\n";
    }

    return 0;

}

#include <iostream>
using namespace std;

int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;

    long long fac = 1;
    for (long long i{2}; i <= n; i++)
    {
        fac *= i;
    }

    cout << fac << "\n";
}
#include<iostream>
using namespace std;
int n, sum, ans = 1e9;
int main() {
	cin >> n;
	if(n==1 || n==3) cout << -1;
	else if ((n % 5) % 2 == 0) cout << n / 5 + (n % 5) / 2;
	else cout << (n / 5 - 1) + ((n % 5) + 5) / 2;
	return 0;
}
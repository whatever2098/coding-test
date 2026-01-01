#include <iostream>
#define ll long long
using namespace std;


ll pow(ll a, ll b, ll c) {
	if (b == 1) { return a % c; }
	ll val = pow(a, b / 2, c);
	val = val * val % c;
	if (b % 2 == 0) return val;
	return val * a % c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll A, B, C;
	cin >> A >> B >> C;
	cout << pow(A, B, C);
}
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int N, X;
	std::cin >> N >> X;
	while (N--) {
		int a;
		std::cin >> a;
		if (a < X) { std::cout << a << " "; }
	}
}
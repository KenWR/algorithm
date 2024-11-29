#include <ios>
#include <iostream>

int	a, b, c, d, e, f;

int	main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> a >> b >> c >> d >> e >> f;
	for (int x = -999; x <= 999; x++) {
		for (int y = -999; y <= 999; y++) {
			if (a * x + b * y == c && d * x + e * y == f) {
				std::cout << x << ' ' << y;
				return 0;
			}
		}
	}
}
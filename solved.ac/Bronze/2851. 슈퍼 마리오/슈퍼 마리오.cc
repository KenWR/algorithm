#include <complex>
#include <cstddef>
#include <ios>
#include <iostream>

int	mushroom[10], point, answer;

int	main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	for (int i = 0; i < 10; i++) {
		std::cin >> mushroom[i];
	}
	// 완전탐색
	for (int i = 0; i < 10; i++) {
		point += mushroom[i];
		if (std::abs(100 - point) <= std::abs(100 - answer)) {
			answer = point;
		}
	}
	std::cout << answer;
}
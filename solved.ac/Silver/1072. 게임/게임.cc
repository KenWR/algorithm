#include <cstddef>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <iterator>

std::size_t	X, Y;

void	search(std::size_t Z) {
	int	low = 0, mid, high = 1000000000;

	while (low <= high) {
		mid = (low + high) / 2;
		if (((Y + mid) * 100) / (X + mid) <= Z) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	std::cout << low;
}

int	main() {
	std::size_t	Z, namuzi, max = 0;

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> X >> Y;
	if (Y == 0) {
		Z = 0;
		search(Z);
		return 0;
	}
	Z = (Y * 100) / X;
	if (Z >= 99) {
		std::cout << -1;
		return 0;
	}
	search(Z);
}
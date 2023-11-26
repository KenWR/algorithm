#include <cstddef>
#include <iostream>
#include <array>
#include <iterator>

int		N, moo_len = 3;

void	divide_and_conquer(int	times);

int	main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;
	divide_and_conquer(4);
}

void		divide_and_conquer(int	times) {
	if (N > moo_len) {
		moo_len = moo_len * 2 + times;
	}
	else {
	
	}
}

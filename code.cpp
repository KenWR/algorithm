#include <cstddef>
#include <cstring>
#include <iostream>
#include <array>
#include <iterator>
#include <string>
#include <string.h>

std::size_t		N;

void	divide_and_conquer(std::string base_moo, std::string more_moo);

int	main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;
	divide_and_conquer("moo", "mooo");
}

void		divide_and_conquer(std::string base_moo, std::string more_moo) {
	std::string	moo = base_moo;
	if (N > base_moo.length()) {
		divide_and_conquer(base_moo + more_moo, more_moo + 'o');
	}
	std::cout << moo;
}

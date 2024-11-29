#include <iostream>
#include <array>
#include <string>

int										N;
std::string									color;
std::array<std::array<char, 64>, 64> 	quad_tree;

void	divide_and_conquer(int	x, int y, int limit);

int	main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> color;
		for (int j = 0; j < N; j++) {			
			quad_tree[i][j] = color[j];
		}
	}
	divide_and_conquer(0, 0, N);
}

void	divide_and_conquer(int	x, int y, int limit) {
	int		next_limit = limit / 2;
	char	now_color = quad_tree[x][y];
	if ((x % 2 == 1 || y % 2 == 1) && limit > 1) {
		return ;
	}
	if (limit > 1) {
		for (int i = 0; i < limit; i++) {
			for (int j = 0; j < limit; j++) {
				if (quad_tree[x + i][y + j] != now_color) {
					std::cout << '(';
					divide_and_conquer(x, y, next_limit);
					divide_and_conquer(x, y + next_limit,next_limit);
					divide_and_conquer(x + next_limit, y, next_limit);
					divide_and_conquer(x + next_limit, y + next_limit, next_limit);
					std::cout << ')';
					return ;
				}
			}
		}
	}
	std::cout << now_color;
	return ;
}
#include <iostream>
#include <array>
#define BLUE true
#define WHITE false

int										N, num_white, num_blue;
bool									color;
std::array<std::array<bool, 130>, 130> 	confetti;

void	divide_and_conquer(int	x, int y, int limit);

int	main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {			
			std::cin >> color;
			confetti[i][j] = color;
		}
	}
	divide_and_conquer(0, 0, N);
	std::cout << num_white << std::endl;
	std::cout << num_blue;
}

void	divide_and_conquer(int	x, int y, int limit) {
	int		next_limit = limit / 2;
	bool	now_color = confetti[x][y];
	if (limit > 1) {
		for (int i = 0; i < limit; i++) {
			for (int j = 0; j < limit; j++) {
				if (confetti[x + i][y + j] != now_color) {
					divide_and_conquer(x, y, next_limit);
					divide_and_conquer(x, y + next_limit / 2,next_limit);
					divide_and_conquer(x + next_limit / 2, y, next_limit);
					divide_and_conquer(x + next_limit / 2, y + next_limit / 2, next_limit);
					return ;
				}
			}
		}
	}
	if (now_color == BLUE) {
		num_blue++;
	}
	else {
		num_white++;
	}
	return ;
}
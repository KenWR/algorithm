#include <iostream>
#include <array>

int										N, color, negative, zero, positive;
std::array<std::array<int, 2187>, 2187> confetti;

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
	std::cout << negative << std::endl << zero << std::endl << positive;
}

void	divide_and_conquer(int	x, int y, int limit) {
	char	now_num = confetti[x][y];
	if (limit > 1) {
		for (int i = 0; i < limit; i++) {
			for (int j = 0; j < limit; j++) {
				if (confetti[x + i][y + j] != now_num) {
					divide_and_conquer(x, y, limit / 3);
					divide_and_conquer(x, y + limit / 3, limit / 3);
					divide_and_conquer(x + limit / 3, y, limit / 3);
					divide_and_conquer(x + limit / 3, y + limit / 3, limit / 3);
					divide_and_conquer(x, y + limit / 3 + limit / 3, limit / 3);
					divide_and_conquer(x + limit / 3 + limit / 3, y, limit / 3);
					divide_and_conquer(x + limit / 3 + limit / 3, y + limit / 3 + limit / 3, limit / 3);
					divide_and_conquer(x + limit / 3 + limit / 3, y + limit / 3, limit / 3);
					divide_and_conquer(x + limit / 3, y + limit / 3 + limit / 3, limit / 3);
					return ;
				}
			}
		}
	}
	if (now_num > 0) {
		positive++;
	}
	else if (now_num < 0) {
		negative++;
	}
	else {
		zero++;
	}
	return ;
}
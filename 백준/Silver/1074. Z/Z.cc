#include <iostream>
#include <array>

int											N, r, c, count; 
bool										check = true;

void	divide_and_conquer(int	x, int y, int limit);

int	main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> r >> c;
	divide_and_conquer(0, 0, (1 << N));
}

void	divide_and_conquer(int x, int y, int limit) {

	if (check && limit >= 4 && (x <= r && r <= x + limit) && (y <= c && c <= y + limit)) {
		divide_and_conquer(x, y, limit / 2);
		divide_and_conquer(x, y + limit / 2, limit / 2);
		divide_and_conquer(x + limit / 2, y, limit / 2);
		divide_and_conquer(x + limit / 2, y + limit / 2, limit / 2);
	}
	if (!((x <= r && r <= x + limit) && (y <= c && c <= y + limit))) {
		count += limit * limit;
	}
	else if (limit == 2 && (x <= r && r <= x + limit) && (y <= c && c <= y + limit)) {
		for (int i = 0; i < limit; i++) {
			for (int j = 0; j < limit; j++) {
				if (x + i == r && y + j == c) {
					std::cout << count;
					check = false;
				}
				count++;
			}
		}
	}
}
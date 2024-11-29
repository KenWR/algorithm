#include <iostream>
#include <algorithm>

bool	visited[55][55];
int		T, M, N, K, farm[55][55], count; //N = y, M = x 좌표로 계산
int		dy[4] = {-1, 0, 0, 1}, dx[4] = {0, -1, 1, 0};

void	recursive(int y, int x);

int	main() {
	int	y, x;// 높이, 폭

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> T;
	while (T) {
		std::cin >> N >> M >> K;
		std::fill_n(&visited[0][0], 55 * 55, false);
		std::fill_n(&farm[0][0], 55 * 55, false);
		count = 0;
		for (int i = 0; i < K; i++) {
			std::cin >> y >> x;
			farm[y + 1][x + 1] = 1;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!visited[i][j] && farm[i][j]) {
					recursive(i, j);
					count++;
				}
			}
		}
		std::cout << count << '\n';
		T--;
	}
}

void	recursive(int y, int x) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		if (!visited[y + dy[i]][x + dx[i]] && farm[y + dy[i]][x + dx[i]]) {
			recursive(y + dy[i], x + dx[i]);
		}
	}
}
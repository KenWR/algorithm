#include <iostream>
#include <algorithm>

bool	visited[105][105];
int		N, M, times, cheese[105][105];
int		dy[4] = {-1, 0, 0, 1}, dx[4] = {0, -1, 1, 0};

int	find_cheese() {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (cheese[i][j] == 1) {
				return 1;
			}
		}
	}
	return 0;
}

void	out_air(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) {
		return ;
	}
	cheese[y][x] = -1;
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		if (cheese[y + dy[i]][x + dx[i]] <= 0 && !visited[y + dy[i]][x + dx[i]]) {
			out_air(y + dy[i], x + dx[i]);
		}
	}
}

int	is_melt(int y, int x) {
	int	melt = 0;
	for (int i = 0; i < 4; i++) {
		if (cheese[y + dy[i]][x + dx[i]] == -1) {
			melt++;
		}
	}
	if (melt > 1) {
		return 1;
	}
	return 0;
}

void	melt_cheese(int y, int x) {
	if (y <= 0 || x <= 0 || y >= N || x >= M) {
		return ;
	}
	visited[y][x] = true;
	if (is_melt(y, x)) {
		cheese[y][x] = 0;
	}
	for (int i = 0; i < 4; i++) {
		if (cheese[y + dy[i]][x + dx[i]] == 1 && !visited[y + dy[i]][x + dx[i]]) {
			melt_cheese(y + dy[i], x + dx[i]);
		}
	}
}

int	main() {
	int	y, x;// 높이, 폭

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> cheese[i][j];
		}
	}
	while (find_cheese()) {
		std::fill_n(&visited[0][0], 105 * 105, false);
		out_air(0, 0);
		std::fill_n(&visited[0][0], 105 * 105, false);
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < M; j++) {
				if (cheese[i][j] == 1 && !visited[i][j]) {
					melt_cheese(i, j);
				}
			}
		}
		times++;
	}
	std::cout << times;
}
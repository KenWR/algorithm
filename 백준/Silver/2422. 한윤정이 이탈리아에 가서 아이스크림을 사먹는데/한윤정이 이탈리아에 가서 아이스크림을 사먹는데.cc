#include <ios>
#include <iostream>

int	N, M, delicious, not_delicious;
bool	not_delicious_comb[201][201];

int	main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	// 맛없는 조합식 구하기
	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int	comb1, comb2;
		std::cin >> comb1 >> comb2;
		not_delicious_comb[comb1][comb2] = true;
		not_delicious_comb[comb2][comb1] = true;
	}
	// 완전탐색
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) { 
			if (i == j) {
				continue;
			}
			for (int k = 1; k <= N; k++) {
				if (i == k || j == k) {
					
				}
				else if (not_delicious_comb[i][j] \
				|| not_delicious_comb[i][k] \
				|| not_delicious_comb[j][k]) {
					
				}
				else {
					delicious++;
				}
			}
		}
	}
	delicious /= 6;
	std::cout << delicious;
}

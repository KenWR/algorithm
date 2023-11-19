#include <array>
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int N, M, A, B, C; // 섬(노드)의 개수, 다리(간선)의 개수, (A 섬1, B 섬2, C 중량)도로;
std::vector<int> weights;
std::array<bool, 10001> visit;
std::vector<std::pair<int, int>> islands[10001];


void    search();
void	dfs(int weight, int island);

int main() {
	std::pair<int, int> edge;

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> A >> B >> C;
		islands[A].push_back(std::make_pair(B, C));
		islands[B].push_back(std::make_pair(A, C));
		weights.push_back(C);
	}
	std::cin >> A >> B;
	std::sort(weights.begin(), weights.end());
	search();
}

void    search() {
	int	begin = 0, mid, end = M - 1, answer = 0;

	while (begin <= end) {
		mid = (begin + end) / 2;
		visit = {0, };
		dfs(weights[mid], A);
		if (visit[B] == true) {
			answer = std::max(answer, weights[mid]);
			begin = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	std::cout << answer;
}

void	dfs(int weight, int island) {
	visit[island] = true;
	for (int i = 0; i < islands[island].size(); i++) {
		if (visit[islands[island][i].first] == false && islands[island][i].second >= weight) {
			dfs(weight, islands[island][i].first);
		}
	}
}
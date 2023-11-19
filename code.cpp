#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <algorithm>

int M, N, L, lane, answer;
std::pair<int, int> coord;
std::vector<std::pair<int, int>> animals;
std::vector<int> lanes;

void    search();

int main() {
	size_t  x, y;
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> M >> N >> L;
	for (int i = 0; i < M; i++) {
		std::cin >> lane;
		lanes.push_back(lane);
	}
	for (int i = 0; i < N; i++) {
		std::cin >> x >> y;
		coord.first = x;
		coord.second = y;
		animals.push_back(coord);
	}
	std::sort(lanes.begin(), lanes.end());
	search();
}

void    search() {
	int	begin, mid, end;

	for (int i = 0; i < N; i++) {
		begin = 0, end = M - 1;
		while (begin <= end) {
			mid = (begin + end) / 2;
			if (abs(animals[i].first - lanes[mid]) + animals[i].second - L <= 0) {
				answer++;
				break ;
			}
			else if (animals[i].first > lanes[mid]) {
				begin = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
	}
	std::cout << answer;
}
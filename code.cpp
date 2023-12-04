#include <cmath>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

int	T;

void	search(std::vector<int> folded_paper);

int	main() {
	int index;

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> T;
	for (int i = 0; i < T; i++) {
		index = 0;
		std::string	paper;
		std::cin >> paper;
		std::vector<int>	folded_paper;
		while (paper[index]) {
			folded_paper.push_back(paper[index] - '0');
			index++;
		}
		search(folded_paper);
	}
	// 트리구조로
}

void	search(std::vector<int> folded_paper) {
	int	low = 0, high = folded_paper.size() - 1;

	while (low < high) {
		if (folded_paper[low] == folded_paper[high]) {
			std::cout << "NO" << '\n';
			return ;
		}
		else if (low + 2 < high - 2 && ((folded_paper[low] == folded_paper[low + 1] && folded_paper[low] == folded_paper[low + 2]) \
		|| (folded_paper[high] == folded_paper[high - 1] && folded_paper[high] == folded_paper[high - 2]))) {
			std::cout << "NO" << '\n';
			return ;
		}
		low++;
		high--;
	}
	std::cout << "YES" << '\n';
}
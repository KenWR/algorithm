#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
int card_num;
std::vector<int> cards;

int binary_search(int card);

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> card_num;
		cards.push_back(card_num);
	}
	std::sort(cards.begin(), cards.end());
	std::cin >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> card_num;
		std::cout << binary_search(card_num) << ' ';
	}
}

int binary_search(int card){
	int mid, left = 0, right = N - 1, cnt = 0;
	int	s_idx, b_idx;

	while (left + 1 < right){
		mid = (left + right) / 2;
		if (cards[left] <= card && cards[mid] <= card){
			left = mid;
		}
		else {
			right = mid;
		}
	}
	b_idx = left;
	if (right == N - 1 && cards[right] == card)
		b_idx++;
	left = 0, right = N - 1;
	while (left + 1 < right){
		mid = (left + right) / 2;
		if (cards[left] < card && cards[mid] < card){
			left = mid;
		}
		else {
			right = mid;
		}
	}
	s_idx = left;
	if (left == 0 && cards[left] == card)
		s_idx--;
	return (b_idx - s_idx);
}
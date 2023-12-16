#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

size_t	profit;

void	calc_zusik(size_t days);
size_t	find_highest(size_t days, size_t today, vector<int> zusik);

int	main() {
	size_t T, N;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (size_t i = 0; i < T; i++) {
		profit = 0;
		cin >> N;
		calc_zusik(N);
	}
}

void	calc_zusik(size_t days) {
	vector<int> zusik;
	size_t purchased = 0, highest, price; //구매일, 가격

	// 입력받는 주식들 저장
	for (size_t i = 0; i < days; i++) {
		cin >> price;
		zusik.push_back(price);
	}
	// 주식 계산
	highest = find_highest(days, purchased, zusik);
	for (size_t i = 0; i < days; i++) {
		// 최고가를 만나면
		if (highest == i) {
			// 주식 전부 판매
			for (size_t j = purchased; j < highest; j++) {
				profit += zusik[highest] - zusik[j];
			}
			purchased = highest + 1;
			highest = find_highest(days, purchased, zusik);
		}
	}
	cout << profit << '\n';
}

size_t	find_highest(size_t days, size_t purchased, vector<int> zusik) {
	size_t	highest = purchased;
	for (size_t i = purchased; i < days; i++) {
		if (zusik[highest] <= zusik[i]) {
			highest = i;
		}
	}
	return (highest);
}
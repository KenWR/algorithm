#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000;

int N, M, inchul, money, ocha, answer = MAX;
std::vector<int> plan;

int	parametic_search();

int main() {
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> money;
        plan.push_back(money);
    }
    std::cout << parametic_search();
}

int     parametic_search() {
    int low = 0, mid, high = MAX;

	while (low <= high) {
		mid = (low + high) / 2;
		inchul = 1, ocha = 0;
		money = mid;
		for (int i = 0; i < N; i++) {
			if (mid < plan[i]) {
				inchul = M + 1;
				break ;
			}
			else if (money >= plan[i]) {
				money -= plan[i];
				ocha++;
			}
			else {
				money = mid;
				money -= plan[i];
				inchul++;
			}
		}
		if (inchul <= M) {
			if (inchul <= M <= inchul + ocha) {
				answer = std::min(answer, mid);
			}
			high = mid - 1;
		}
		else if (inchul > M) {
			low = mid + 1;
		}
	}
	return (answer);
}


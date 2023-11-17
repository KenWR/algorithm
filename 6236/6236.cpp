#include <iostream>
#include <vector>
#include <algorithm>

int N, M, money;
std::vector<int> plan;

int     parametic_search();
bool    check(int money);

int main() {
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> money;
        plan.push_back(money);
    }
    std::sort(plan.begin(), plan.end());
    std::cout << parametic_search();
}

int     parametic_search() {
    int lower = 0, mid, upper = plan[N - 1];

    while (lower + 1 < upper) {
        mid = (lower + upper) / 2;
        if (check(mid)) {
            lower = mid;
        }
        else {
            upper = mid;
        }
    }
    if (check(lower + 1))
        return (lower + 1);
    return (lower);
}

bool check(int money) {
    int result = 0, pocket = money;

    for (int i = 0; i < N; i++) {
        if (plan[i] > pocket) {
            pocket = money;
            pocket -= money;
            result++;
        }
        else {
            pocket -= money;
        }
    }
    if (result >= M) {
        return true;
    }
    return false;
}
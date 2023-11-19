#include <iostream>
#include <vector>
#include <algorithm>
#define LOW true
#define HIGH false

int N, M, money, highest;
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
        if (money > highest) {
            highest = money;
        }
        plan.push_back(money);
    }
    std::cout << parametic_search();
}

int     parametic_search() {
    int lower = 0, mid, upper = 20000;

    while (lower + 1 < upper) {
        mid = (lower + upper) / 2;
        if (check(mid)) {
            lower = mid;
        }
        else {
            upper = mid;
        }
    }
    return (lower);
}

bool check(int money) {
    int result = 0, pocket = 0;

    for (int i = 0; i < N; i++) {
        if (plan[i] > money)
            return LOW;
        else if (plan[i] >= pocket) {
            pocket = money;
            pocket -= plan[i];
            result++;
        }
        else {
            pocket -= plan[i];
        }
    }
    if (result >= M) {
        return LOW;
    }
    return HIGH;
}
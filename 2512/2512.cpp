#include <cstddef>
#include <iostream>
#include <algorithm>
#include <vector>

int N, M, money;
std::vector<int> provi_m;

int parametic_search();
bool check(int money);

int main() {
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> money;
        provi_m.push_back(money);
    }
    std::sort(provi_m.begin(), provi_m.end());
    std::cin >> M;
    std::cout << parametic_search();
}

int parametic_search() {
    size_t  lower = 0, mid, upper = provi_m[N - 1];

    while (lower + 1 < upper) {
        mid = (lower + upper) / 2;
        if (check(mid)) {
            lower = mid;
        }
        else {
            upper = mid;
        }
    }
    if (check(lower + 1) && lower + 1 <= provi_m[N - 1])
        return (lower + 1);
    return (lower);
}

bool check(int money) {
    size_t  sum;

    sum = 0;
    for (int i = 0; i < N; i++) {
        if (provi_m[i] > money) {
            sum += money;
        }
        else {
            sum += provi_m[i];
        }
    }
    if (sum <= M) {
        return (true);
    }
    else {
        return (false);
    }
}
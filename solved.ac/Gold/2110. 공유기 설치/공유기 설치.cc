#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>

std::size_t N, C, X, answer;
std::vector<std::size_t> houses;
void    search();

int main() {
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::cin >> N >> C;
    for (std::size_t i = 0; i < N; i++) {
        std::cin >> X;
        houses.push_back(X);
    }
    std::sort(houses.begin(), houses.end());
    search();
}

void    search() {
    std::size_t left = 0, mid, right = houses[N - 1] - houses[0], router, distance;

    // 이분탐색
    while (left <= right) {
        router = 1;
        distance = houses[0];
        mid = (left + right) / 2;
        for (int i = 1; i < N; i++) {
            // 거리가 맞을때마다 공유기 숫자 증가
            if (houses[i] - distance >= mid) {
                router++;
                distance = houses[i];
            }
        }
        if (router >= C) {
            answer = std::max(answer, mid);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    std::cout << answer;
}
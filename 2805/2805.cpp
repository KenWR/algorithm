#include <iostream>
#include <algorithm>
// #include <array>
#include <vector>

int N, M, tree;
std::vector<int> trees;

int    binary_search();
bool    cut(int height);

int main() {
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> tree;
        trees.push_back(tree);
    }
    std::sort(trees.begin(), trees.end());
    if (M == 0) {
        std::cout << trees[N - 1];
    }
    else {
        std::cout << binary_search();
    }
}

int    binary_search() {
    int down = 0, mid, up = trees[N - 1];
    
    while (down + 1 < up) {
        mid = (down + up) / 2;
        if (cut(mid)) {
            down = mid;
        }
        else {
            up = mid;
        }
    }
    return (down);
}

bool    cut(int height) {
    int sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (trees[i] > height) {
            sum += trees[i] - height;
        }
        else {
            break;
        }
    }
    if (sum >= M || sum < 0) {
        return (true);
    }
    else {
        return (false);
    }
}

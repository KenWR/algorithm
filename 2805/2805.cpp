#include <iostream>
#include <algorithm>
// #include <array>
#include <vector>

int N, M, tree;
std::vector<int> trees;

int    binary_search();
bool    cut(int idx);

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
    std::cout << binary_search();
}

int    binary_search() {
    int down = 0, mid, up = trees[N - 1], result = 0;
    
    while (down + 1 < up) {
        mid = (down + up) / 2;
        if (cut(mid)) {
            down = mid;
            result = down;
        }
        else {
            up = mid;
        }
    }
    // if (cut(0))
    //     result = 0;
    return (result);
}

bool    cut(int height) {
    int sum = 0, cutted;
    for (int i = N - 1; i >= 0; i--) {
        if (trees[i] > height) {
            sum += trees[i] - height;
        }
        else {
            break;
        }
    }
    if (sum >= M) {
        return (true);
    }
    else {
        return (false);
    }
}
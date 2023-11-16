#include <iostream>
#include <algorithm>
// #include <array>
#include <vector>

int N, M, tree;
std::vector<int> trees;


int main()
{
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> tree;
        trees.push_back(tree);
    }
    std::sort(trees.begin(), trees.end());
    
}
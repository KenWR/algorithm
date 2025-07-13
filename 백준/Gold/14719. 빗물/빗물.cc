// Monotonic Stack
#include <vector>
#include <iostream>
#include <stack>

int GetRainwater(const std::vector<int>& rain_gutter) {
    std::stack<int> st;
    int rainwater = 0;

    for (int i = 0; i < rain_gutter.size(); ++i) {
        // 상향 변곡점 발견견
        while (st.empty() == false && rain_gutter[i] > rain_gutter[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty() == true) {
                break;
            }
            int dist = i - st.top() - 1;
            int lowest_block = std::min(rain_gutter[st.top()], rain_gutter[i]) - rain_gutter[top];
            rainwater += dist * lowest_block;
        }
        st.push(i);
    }

    return rainwater;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int height, width;
    std::cin >> height >> width;

    std::vector<int> rain_gutter;

    int answer = 0;
    int block_height;
    for (int i = 0; i < width; ++i) {
        std::cin >> block_height;
        rain_gutter.push_back(block_height);
    }

    std::cout << GetRainwater(rain_gutter) << '\n';
}

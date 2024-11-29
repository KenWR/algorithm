#include <cstddef>
#include <iostream>
#include <algorithm>
#include <vector>

//입국심사대, 사람, 시간, 번 심사관
std::size_t N, M, T, K;
std::vector<std::size_t> checkpoints;
std::size_t search();
bool check(std::size_t time);
long    set_detail(std::size_t time);

int main() {
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::cin >> N >> M;
    for (std::size_t i = 0; i < N; i++) {
        std::cin >> T;
        checkpoints.push_back(T);
    }
    std::cout << search();
}

std::size_t search() {
    size_t  low = 0, mid, high = M * checkpoints[0], ans, immigration;

    while(high >= low){ 
        immigration = 0;
        mid = (high + low) / 2;
        for (int i = 0; i < N; i++){
            immigration += mid / checkpoints[i]; 
        }
        if(immigration >= M){
            if(ans > mid || ans ==0){ 
                ans = mid;
            }
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
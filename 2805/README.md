### C++

![Alt text](%EB%AC%B8%EC%A0%9C.PNG "문제")

![Alt text](%EC%98%88%EC%A0%9C.PNG "예제")

#### 문제 풀이
문제를 풀 때 `매개 변수 탐색 (Parametric Search)` 알고리즘으로 풀어 내었다.   
기존의 이분 탐색이 *정렬된 배열에서 특정한 값을 찾아내는 것* 이었다면   
 `매개 변수 탐색` 은 *특정한 매개변수 값의 범위 내에서 원하는 조건을 만족하는 최적의 매개변수를 찾는 것* 이다.   
 이진 탐색에서의 중간값이 배열의 중앙이었다면 이 문제에서의 중간값은 나무들의 중간 길이가 된다.   
 각 나무들의 중간 길이를 구하고 그 길이로 나무를 잘랐을때 나오는 값과 상근이가 구하고자하는 나무의 값이 최대한 근접할 수 있는 최소값 (절단기 높이의 최대값) 을 찾을때까지 길이를 구해내었다.

 #### 오답 노트
 <details>

    ```c++
    #include <iostream>
    #include <algorithm>
    #include <array>
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
                up = mid;
                result = up;
            }
            else {
                down = mid;
            }
        }
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
        if (sum > M) {
            return (false);
        }
        else {
            return (true);
        }
    }
    ```

 </details>


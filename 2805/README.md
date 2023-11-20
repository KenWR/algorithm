### C++
---

![Alt text](%EB%AC%B8%EC%A0%9C.PNG "문제")

![Alt text](%EC%98%88%EC%A0%9C.PNG "예제")

#### 문제 풀이
문제를 풀 때 `매개 변수 탐색 (Parametric Search)` 알고리즘으로 풀어 내었다.   
기존의 이분 탐색이 *정렬된 배열에서 특정한 값을 찾아내는 것* 이었다면   
`매개 변수 탐색` 은 *특정한 매개변수 값의 범위 내에서 원하는 조건을 만족하는 최적의 매개변수를 찾는 것* 이다.   
이진 탐색에서의 중간값이 배열의 중앙이었다면 이 문제에서의 중간값은 나무들의 중간 길이가 된다.   
각 나무들의 중간 길이를 구하고 그 길이로 나무를 잘랐을때 나오는 값과 상근이가 구하고자하는 나무의 값이 최대한 근접할 수 있는 최소값 (절단기 높이의 최대값) 을 찾을때까지 길이를 구해내었다.

---

#### 오답 노트
<details>
	<summary>기준을 잘못 설정</summary>

``` c++ 

#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

int N, M, tree;
std::vector<int> trees;

int    parametric_search();
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
std::cout << binary_search();
}

// 매개 변수 탐색
int    parametric_search() {
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

// check
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
	//조건 설정 miss
	if (sum > M) {
		return (false);
	}
	else {
		return (true);
	}
}

```   
	   
절단기 높이 기준을 최소값을 구하는 것이면 cut 함수에서 return 값 기준을 반대로 구해서 그대로 출력을 했어야했는데 엉뚱한 방향으로 구해서 추가적인 예외처리가 필요해져 버린데다 그 예외처리도 하지 않아 제대로된 답이 출력되지 않았다.
</details>

<details>
	<summary>오버플로우</summary>

``` c++

#include <iostream>
#include <algorithm>
#include <vector>

int N, M, tree;
std::vector<int> trees;

int    parametric_search();
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
	//예외처리 추가
	if (M == 0) {
		std::cout << trees[N - 1];
	}
	else {
		std::cout << binary_search();
	}
}

// 매개 변수 탐색
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

// check
bool    cut(int height) {
	int sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (trees[i] > height) {
			// !! 오버플로우
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

```

M 값이 0일경우 값이 제대로 나오지 않아 예외처리를 해 주었고 조건 설정을 간단히 바꿔주었다.   
하지만 type 설정을 제대로 하지 않아 틀리게 되었는데 문제에서 주어진 M의 조건이 20억까지 주어져서 sum 을 구하는 부분에 있어 오버플로우가 일어나게 되었다.

</details>

문제를 꼼꼼히 읽어봐야겠다고 생각이들었다.   
그렇지만 솔직히 문제가 너무 더럽다.  
그래도 조금더 신중하게 그리고 어떻게 진행되는지에 대한 여부까지 예상하며 만들어야겠다.

---

#### 맞은 코드

``` c++

#include <cstddef>
#include <iostream>
#include <algorithm>
#include <vector>

std::size_t N, M, tree;
std::vector<int> trees;

std::size_t		binary_search();
bool			cut(std::size_t height);

int main() {
	// cin&cout 출력시간 단축
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N >> M;
	// N 개 만큼의 나무를 배열에 삽입
    for (int i = 0; i < N; i++) {
        std::cin >> tree;
        trees.push_back(tree);
    }
	// 나무들을 정렬
    std::sort(trees.begin(), trees.end());
	// 예외처리...
    if (M == 0) {
        std::cout << trees[N - 1];
    }
    else {
        std::cout << binary_search();
    }
}

// 매개 변수 탐색
std::size_t    binary_search() {
    std::size_t down = 0, mid, up = trees[N - 1];
    
	// true와 false가 교차하는 지점까지 반복
    while (down + 1 < up) {
		// 매 순간 기준을 정해준다.
        mid = (down + up) / 2;
		// 해당 높이가 기준에 부합하면 
		// 해당 목재 절단기의 높이가 낮은것은 찾을 필요가 없으니 down = mid 를 해준다.
        if (cut(mid)) {
            down = mid;
        }
		// 부합하지 않으면 목재 절단기의 높이를 낮춰준다.
        else {
            up = mid;
        }
    }
    return (down);
}

// check
bool    cut(std::size_t height) {
    std::size_t sum = 0;

	// 정렬된 나무들은 가장 큰 나무가 뒤에 있을테니
	// 뒤에서부터 비교하여 차이값(잘라낸 나무)을 sum에 모은다.
    for (int i = N - 1; i >= 0; i--) {
        if (trees[i] > height) {
            sum += trees[i] - height;
        }
        else {
            break;
        }
    }
	// 잘라낸 나무들의 크기가 원하는 값보다 크거나 작으면 true
	// M 이라는 값을 확정적으로 얻어야하기에 sum 의 값은 같거나 커야한다.
    if (sum >= M) {
        return (true);
    }
	// 그 외에는 false
    else {
        return (false);
    }
}

```

나무들을 받아와 배열에 집어넣고   
해당 배열을 정렬을 해주고   
매개 변수 탐색으로 나무 길이를 기준으로 중간값으로 기준을 잡아 원하는 양 만큼의 나무의 M 을 얻을 수 있는 최소값을 얻기위해   
check 함수가 true 와 false 를 교차하며 뱉어내거나 끝에 다다를때까지 반복을 돌려주어 가장 최소값인 down 을 출력해 준다.

여기서 배운것은 이분탐색이란 세상 모든걸 반으로 나누는게 아니라 
시간복잡도가 O(2n)인 상황에서 하나의  O(n) 이 정렬되어 있고 그 양이 일일이 대입하기 어려울경우에만
반씩나누어 O(n log(n)) 을 만드는 것이다.

#### 리팩토링
---

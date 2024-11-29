#include <algorithm>
#include <iostream>
using namespace std;

int sum_arr[505];
int plus_arr[505];

int	main() {
    int N, biggest = 0;

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        // 한줄씩 받아오기
        for (int j = 0; j < i; j++) {
            cin >> plus_arr[j];
        }
        // 한줄씩 가장 큰 수로 더해주기
        for (int j = 0; j < i; j++) {
            if (j != 0 && j != i - 1) {
                plus_arr[j] += max(sum_arr[j - 1], sum_arr[j]);
            }
            else if (j == 0) {
                plus_arr[j] += sum_arr[j];
            }
            else if (j == i - 1) {
                plus_arr[j] += sum_arr[j - 1];
            }
        }
        // 더해진 값을 sum_arr에 복사
        for (int j = 0; j < i; j++) {
            sum_arr[j] = plus_arr[j];
        }
    }
    // 순회하며 가장 큰 수 출력
    for (int i = 0; i < N; i++) {
        biggest = max(biggest, sum_arr[i]);
    }
    cout << biggest;
}
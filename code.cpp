#include <iostream>
#include <vector>
using namespace std;

size_t	stairs[105][11];

int	main() {
    int N, step;
    size_t stair_num = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for (int i = 0; i < 10; i++) {
        stairs[1][i] = 1;
    }
	cin >> N;
    for (int i = 2; i <= N; i++) { // 자릿수
        for (int j = 0; j < 10; j++) { // 시작 번호
            stairs[i][j] = 0;
            if (j - 1 >= 0) stairs[i][j] += stairs[i - 1][j - 1];
            if (j + 1 < 10) stairs[i][j] += stairs[i - 1][j + 1];
            stairs[i][j] %= 1000000000;
        }
    }
    for (int i = 1; i < 10; i++) {
        stair_num = (stair_num + stairs[N][i]) % 1000000000;
    }
    cout << stair_num % 1000000000;
}
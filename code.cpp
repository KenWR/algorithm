#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

int sticker[2][100005];

int	main() {
	int T, n;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	while (T--> 0) {
        cin >> n;
		// 배열 초기화
        for (int i = 0; i < 2; i++) {
            fill(begin(sticker[i]), end(sticker[i]), 0);
        }
        // 스티커 점수 삽입
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> sticker[i][j];
            }
        }
        // 스티커 최대합 계산
        for (int i = 2; i <= n; i++) {
            sticker[0][i] = max(sticker[1][i - 1], sticker[1][i - 2]) + sticker[0][i];
            sticker[1][i] = max(sticker[0][i - 1], sticker[0][i - 2]) + sticker[1][i];
        }
        cout << max(sticker[0][n], sticker[1][n]) << '\n';
	}
}

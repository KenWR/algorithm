#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int zero[41];
int one[41];
void	dynamic_p(int n);

int	main() {
	int N, T;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	zero[0] = 1;
	one[1] = 1;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		dynamic_p(N);
		cout << zero[N] << ' '; // 0 개수 출력
		cout << one[N] << '\n'; // 1 개수 출력
	}
	return (0);
}

void	dynamic_p(int n) {
	if (n == 0 || n == 1) {
		return;
	}
	if (zero[n - 1] == 0 && one[n - 1] == 0) {
		dynamic_p(n - 1);
	}
	if (zero[n - 2] == 0 && one[n - 2] == 0) {
		dynamic_p(n - 2);
	}
	zero[n] = zero[n - 1] + zero[n - 2];
	one[n] = one[n - 1] + one[n - 2];
}
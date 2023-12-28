#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<long> wave;

int	main() {
	int T, N;

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
    for (int i = 0; i < 3; i++) {
        wave.push_back(1);
    }
    for (int i = 3; i <= 100; i++) {
        wave.push_back(wave[i - 2] + wave[i - 3]);
    }
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        cout << wave[N - 1] << '\n';
    }
}

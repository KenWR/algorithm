#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

void	sorting_log(int log_num);
void	calc_level(vector<int> logs);

int	main() {
	int T, N, L; // 테스트 개수, 통나무 개수, 통나무 높이
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		sorting_log(N);
	}
}

void	sorting_log(int log_num) {
	vector<int> logs, new_logs;
	int	log;
	bool flag = false;

	// 통나무 배열로 받기
	for (int i = 0; i < log_num; i++) {
		cin >> log;
		logs.push_back(log);
	}
	// 통나무 오름차순 정렬
	sort(logs.begin(), logs.end());
	new_logs.push_back(logs[log_num - 1]);
	for (int i = log_num - 2; i >= 0; i--) {
		if (flag == false) {
			new_logs.insert(new_logs.begin(), logs[i]);
			flag = true;
		}
		else if (flag == true) {
			new_logs.push_back(logs[i]);
			flag = false;
		}
	}
	calc_level(
		new_logs);
}

void calc_level(vector<int> logs) {
	int	level = 0;

	for (int i = 1; i < logs.size(); i++) {
		level = max(abs(logs[i - 1] - logs[i]), level);
	}
	cout << level << '\n';
}
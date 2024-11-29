#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

void	judge_recruits(int recruits_num);
bool	compare(pair<int, int> a, pair<int, int> b);

int	main() {
	int T, N;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		judge_recruits(N);
	}
}

void	judge_recruits(int recruits_num) {
	vector<pair<int, int>> recruits;
	pair<int, int> recruit;
	int	rank, count = 0; // 기록, 뽑을 신입사원 수

	// 신입사원들 배열로 만들기
	for (int i = 0; i < recruits_num; i++) {
		cin >> recruit.first >> recruit.second;
		recruits.push_back(recruit);
	}
	// 정렬
	sort(recruits.begin(), recruits.end(), compare);
	rank = recruits[0].second;
	// 신입사원정리
	for (int i = 1; i < recruits_num; i++) {
		if (recruits[i].second < rank) {
			rank = recruits[i].second;
			count++;
		}
	}
	cout << count + 1 << '\n';
}

bool	compare(pair<int, int> a, pair<int, int> b) {
	return (a.first < b.first);
}
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

void	judge_recruits(int recruits_num);
bool	compare_fir(pair<int, int> a, pair<int, int> b);
bool	compare_sec(pair<int, int> a, pair<int, int> b);

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
	vector<pair<int, int>> recruits, sorted_myunzub, sorted_both;
	pair<int, int> recruit, myunzub_no_1, seoryu_no_1;

	// 신입사원들 배열로 만들기
	for (int i = 0; i < recruits_num; i++) {
		cin >> recruit.first >> recruit.second;
		if (recruit.first == 1)
			seoryu_no_1 = recruit;
		else if (recruit.second == 1)
			myunzub_no_1 = recruit;
		recruits.push_back(recruit);
	}
	// 서류 1위의 면접 점수보다 낮은 사람 제거
	for (int i = 0; i < recruits_num; i++) {
		if (recruits[i].second <= seoryu_no_1.second)
			sorted_myunzub.push_back(recruits[i]);
	}
	// 면접 1위의 서류 점수보다 낮은 사람 제거
	for (int i = 0; i < sorted_myunzub.size(); i++) {
		if (sorted_myunzub[i].first <= myunzub_no_1.first)
			sorted_both.push_back(sorted_myunzub[i]);
	}
	cout << sorted_both.size() << '\n';
}


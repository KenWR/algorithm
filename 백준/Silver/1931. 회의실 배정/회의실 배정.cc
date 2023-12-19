#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> meet_info_arr;

bool	ascending_fir(const pair<int, int> &a, const pair<int, int> &b);
void	scheduling(int meet_num);

int	main() {
	int N, m_start, m_end; // 회의개수, 시작시간, 끝시간
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> m_start >> m_end;
		meet_info_arr.push_back(make_pair(m_start, m_end));
	}
	sort(meet_info_arr.begin(), meet_info_arr.end(), ascending_fir);
	scheduling(N);
}

bool	ascending_fir(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first)
        return (a.second < b.second);
	return (a.first < b.first);
}

void	scheduling(int meet_num) {
	int	count = 0;
	pair<int, int> meet_info;
	
	for (int i = 0; i < meet_num; i++) {
		if (meet_info_arr[i].first >= meet_info.second) {
			meet_info = meet_info_arr[i];
			count++;
		}
		if (meet_info_arr[i].second < meet_info.second) {
			meet_info = meet_info_arr[i];
		}
	}
	cout << count;
}

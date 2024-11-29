#include <iostream>
#include <array>
#include <queue>
#include <string>
using namespace std;

int BFS();
int N, M, visited[1005][1005][2];
int map[1005][1005], dy[4] = {-1, 0, 0, 1}, dx[4] = {0, -1, 1, 0};
queue<struct man> q;

struct  man {
	int y;
	int x;
	int dist;
	bool    broke;
};

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++){
			map[i][j] = str[j - 1] - '0';
		}
	}   // 입력
	cout << BFS();
}

int    BFS() {
	visited[1][1][0] = true;
	visited[1][1][1] = true;
	q.push({1, 1, 1, 0});
	while (!q.empty()) {
		man now = q.front();
		q.pop();
		if (now.y == N && now.x == M) {
			return now.dist;
		}
		for (int i = 0; i < 4; i++) {
			int	y = now.y + dy[i];
			int	x = now.x + dx[i];
			if (!(y >= 1 && y <= N && x >= 1 && x <= M)) continue;
			if (visited[y][x][now.broke]) continue;
			if (!map[y][x]) {
				q.push({y,x, now.dist + 1, now.broke});
				visited[y][x][now.broke] = true;
			}
			else if (now.broke == 1) continue;
			else {
				q.push({y, x, now.dist + 1, true});
				visited[y][x][1] = true;
			}
		}
	}
	return (-1);
}
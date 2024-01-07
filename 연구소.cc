#include <iostream>
#define VIRUS 2
#define WALL 1
#define SAFE 0
using namespace std;

const int dy[4] = {-1, 0, 0, 1}, dx[4] = {0, 1, -1, 0};
int N, M, lab[10][10];

int    count_area(int src);
int    count_bfs(int y, int x, bool visited[10][10], int size, int source);
void    spread(int dest, int src);
void    spread_bfs(int y, int x, bool visited[10][10], int dest, int source);

int	main() {
    int size = 0;

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> lab[i][j];
        }
    }
    cout << count_area(SAFE) << ' ' << count_area(VIRUS);
    spread(SAFE, VIRUS);
    return 0;
}


int    count_area(int src) {
    int size = 0;
    bool    visited[10][10] = {false, };

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (lab[i][j] == src)
                size = count_bfs(i, j, visited, size, src);
        }
    }
    return (size);
}

int count_bfs(int y, int x, bool visited[10][10], int size, int source) {
    if (y == 0 || x == 0 || y > N || x > M) // 범위 벗어나면 종료
        return (0);
    visited[y][x] = true;
    size++;
    for (int i = 0; i < 4; i++) {
        if (lab[y + dy[i]][x + dx[i]] == source \
        && visited[y + dy[i]][x + dx[i]] == 0)
            count_bfs(y + dy[i], x + dx[i], visited, size, source);
    }
    return (size);
}

void    spread(int dest, int src) {
    bool    visited[10][10] = {false, };

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (lab[i][j] == dest)
                spread_bfs(i, j, visited, dest, src);
        }
    }
    return;
}

void    spread_bfs(int y, int x, bool visited[10][10], int dest, int source) {
    if (y == 0 || x == 0 || y > N || x > M) // 범위 벗어나면 종료
        return;
    visited[y][x] = true;
    lab[y][x] = source;
    for (int i = 0; i < 4; i++) {
        if (lab[y + dy[i]][x + dx[i]] == dest \
        && visited[y + dy[i]][x + dx[i]] == 0)
            spread_bfs(y + dy[i], x + dx[i], visited, dest, source);
    }
}
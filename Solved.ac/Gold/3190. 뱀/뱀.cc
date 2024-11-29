#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef struct s_snake {
    int y;
    int x;
} t_snake;

int N, K, L;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int board[105][105];
int movement[2][105];

int play_game(int y, int x, int head);
int replace_head(int head);

int	main() {
	int x, y;
    char direction;

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
    cin >> N >> K;
    // 사과좌표
    for (int i = 0; i < K; i++) {
        cin >> y >> x;
        board[y][x] = 1;
    }
    // 뱀 이동 first = 이동거리일때 second = 방향전환
    // dy, dx는 오른쪽으로 [1]고정 
    // L = head - 1, D = head + 1
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> movement[0][i] >> direction;
        movement[1][i] = direction;
    }
    cout << play_game(1, 1, 1);
}

int    play_game(int y, int x, int head) {
    deque<t_snake> snake;
    t_snake pos;
    int next_move = 0;
    size_t  sec = 0;

    pos.y = 1, pos.x = 1;
    snake.push_front(pos);
    while (1) {
        sec++;
        pos.y += dy[head];
        pos.x += dx[head];
        snake.push_front(pos);
        // 벽이나 자신을 만나면 종료
        if (snake.front().y == 0 || snake.front().x == 0\
        || snake.front().y > N || snake.front().x > N)
            return (sec);
        for (int i = 1; i < snake.size(); i++) {
            if (snake[i].y == snake.front().y \
            && snake[i].x == snake.front().x)
                return (sec);
        }
        if (board[snake.front().y][snake.front().x] == 0)
            snake.pop_back();
        if (board[snake.front().y][snake.front().x] == 1)
            board[snake.front().y][snake.front().x] = 0;
        while (sec == movement[0][next_move]) {
            if (movement[1][next_move] == 'L')
                head--;
            else if (movement[1][next_move] == 'D')
                head++;
            next_move++;
        }
        head = replace_head(head);
    }
    return (sec);
}

int replace_head(int head) {
    if (head < 0)
        return (head + 4);
    else if (head > 3)
        return (head - 4);
    return (head);
}
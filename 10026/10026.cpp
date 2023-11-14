//적록색약

#include <iostream>
#include <string>

int	N, now_color, paint[105][105];
bool visit[105][105] = {false};
int	dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int	dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int	non_blind_sight, red_green_sight;
std::string  draw;

void	red_green_color_blind(int node, int start){

}

void	non_blind(int node, int start){
	if (node > N || node < 1 || start > N || start < 1)
		return ;
	visit[node][start] = true;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (visit[node + dx[i]][start + dy[j]] == false && paint[node + dx[i]][start + dy[j]] == now_color){
				non_blind(node + dx[i], start + dy[j]);
			}
		}
	}
	//non_blind(node, start);
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;
	for (int i = 1; i <= N; i++){
		std::cin >> draw;
		for(int j = 1; j <= N; j++){
			paint[i][j] = draw[j] - 'A';
		}
	}
	//정상
	for (int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if (visit[i][j] == false && paint[i][j] != 0){
				non_blind_sight++;
				now_color = paint[i][j];
				non_blind(i, j);
			}
		}
	}
	std::cout << non_blind_sight << ' ';
	//색맹
}
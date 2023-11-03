#include <iostream>
#include <list>
#include <queue>
#include <string>
#define VISITED 3
#define MAX_NODES 1005
using namespace std;

int	visited_dfs[MAX_NODES];
int	visited_bfs[MAX_NODES];
int matrix[MAX_NODES][MAX_NODES];
queue <int> bfs_que;

void	dfs(int node_num, int start)
{
	visited_dfs[start] = VISITED;
	cout << start;
	cout << ' ';
	for (int i = 0; i < node_num; i++)
	{
		if (matrix[start - 1][i] == 1 && visited_dfs[i + 1] != VISITED)
			dfs(node_num, i + 1);
	}

}

void	bfs(int node_num, int start)
{
	bfs_que.push(start);
	visited_bfs[start] = VISITED;
	while (!bfs_que.empty())
	{
		cout << bfs_que.front();
		cout << ' ';
		for (int i = 0; i < node_num; i++)
		{
			if (matrix[bfs_que.front() - 1][i] == 1 && visited_bfs[i + 1] != VISITED)
			{
				visited_bfs[i + 1] = VISITED;
				bfs_que.push(i + 1);
			}
		}
		bfs_que.pop();
	}
}

int main()
{
	int	node_num, edge_num, fir_idx, sec_idx, start;

    cin >> node_num >> edge_num >> start;
	for (int i = 0; i < edge_num; i++)
	{
		cin >> fir_idx >> sec_idx;
		matrix[fir_idx - 1][sec_idx - 1] = 1;
		matrix[sec_idx - 1][fir_idx - 1] = 1;
	}
	dfs(node_num, start);
	cout << endl;
	bfs(node_num, start);
	return (0);
}
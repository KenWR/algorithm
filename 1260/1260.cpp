#include <iostream>
#include <list>
#define VISITED 3
#define MAX_NODES 1000
using namespace std;

typedef struct s_node
{
	int	node_num;
	struct s_node *next;
}	t_node;

int	visited[MAX_NODES];

void	dfs(int start)
{
	
}

int	main()
{
	int	node_num, edge_num, start_node;
	int fir_index, sec_index;
	
	cin >> node_num >> edge_num >> start_node;
	//인접행렬 리스트 생성
	for (int i = 1; i <= node_num; i++)
	{
		
	}
	while (edge_num)
	{
		cin >> fir_index >> sec_index;
		graph[fir_index];
		edge_num--;
	}
	dfs(start_node);
	cout << endl;
	bfs();
	return (0);
}

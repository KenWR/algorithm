#include <iostream>
#include <list>
using namespace std;

int graph[1000][1000];

void	dfs(int start)
{
	
}

int	main()
{
	int	node, edge, start;
	int fir_index, sec_index;
	
	cin >> node >> edge >> start;
	//인접행렬 그래프 생성
	while (edge)
	{
		cin >> fir_index >> sec_index;
		graph[fir_index][sec_index] = 1;
		graph[sec_index][fir_index] = 1;
		edge--;
	}
}

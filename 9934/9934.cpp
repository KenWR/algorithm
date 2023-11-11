#include <iostream>

static int cbt[1030];
//1, 6, 4, 3, 5, 2, 7
//3, 6, 2, 1, 4, 5, 7

void	complete_binary_tree(int node_num)
{
	if (node_num > 7)
		return ;
	complete_binary_tree((node_num * 2));
	std::cin >> cbt[node_num];
	complete_binary_tree((node_num * 2) + 1);
}

int main()
{
	int	node_num = 3;
	complete_binary_tree(1);
	for (int i = 1; i <= 7; i++)
	{
		std::cout << cbt[i] << ' ';
		if ()
	}
}
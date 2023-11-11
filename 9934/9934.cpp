#include <iostream>

static int cbt[1030];

void	complete_binary_tree(int node_num, int k)
{
	if (node_num > (1<<k) - 1)
		return ;
	complete_binary_tree(node_num * 2, k);
	std::cin >> cbt[node_num];
	complete_binary_tree((node_num * 2) + 1, k);
}

int main()
{
	int	node_num = 1;
	int	k;
	int	a = 1;

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> k;
	complete_binary_tree(node_num, k);
	for (int i = 1; i <= (1<<k) - 1; i++)
	{
		std::cout << cbt[i] << ' ';
		if (1 && i == (1<<a) - 1)
		{
			std::cout << std::endl;
			a++;
		}
	}
}
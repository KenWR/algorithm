// #include <iostream>
// #include <string.h>
// #include <string>

// int 	R, C;
// char	map[20][20];
// char	visit[26];
// int		move = 0, final = 0;

// int	check_visit(char c)
// {
// 	int	i = 0;
// 	while (visit[i])
// 	{
// 		if (visit[i] == c)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// void	recursive(int start)
// {
// 	int		idx = 0;

// 	if (start == R)
// 		return ;
// 	for (int i = 0; i < R; i++)
// 	{
// 		if (check_visit(map[start][i]))
// 		{
// 			visit[move] = map[start][i];
// 			move++;
// 			if (move > final)
// 				final = move;
// 			recursive(start + 1);
// 		}
// 	}
// 	move--;
// }

// int main()
// {
// 	std::string	alpha;

// 	std::cin >> R >> C;
// 	for (int i = 0; i < R; i++)
// 	{
// 		std::cin >> alpha;
// 		for (int j = 0; j < C; j++)
// 		{
// 			map[i][j] = alpha[j];
// 		}
// 	}
// 	recursive(0);
// 	std::cout << final;
// }
#include <iostream>
#include <string>

int R, C;
char map[20][20];
bool visit[26] = {false}; 

int move = 0, final = 0;

void recursive(int start, int x, int y) 
{
    if (x < 0 || x >= R || y < 0 || y >= C) 
        return;

    if (visit[map[x][y] - 'A']) 
        return;
    visit[map[x][y] - 'A'] = true; 
    move++;
    if (move > final)
        final = move;
    recursive(start + 1, x + 1, y); 
    recursive(start + 1, x - 1, y); 
    recursive(start + 1, x, y + 1);
    recursive(start + 1, x, y - 1); 
    move--;
    visit[map[x][y] - 'A'] = false;
}

int main()
{
    std::string alpha;

    std::cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        std::cin >> alpha;
        for (int j = 0; j < C; j++)
        {
            map[i][j] = alpha[j];
        }
    }

    recursive(0, 0, 0);

    std::cout << final;

    return 0;
}

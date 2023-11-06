#include <iostream>
#include <list>
#include <string>
#include <stdlib.h>
#define VISITED 'V'
#define MAX_NODES 51
using namespace std;

int	    visited_dfs[MAX_NODES];
int		count = 0;
char    matrix[MAX_NODES][MAX_NODES];

void	count_right(int	f, int s, int sec_idx)
{
	for (int i = 0; i < sec_idx; i++)
	{
		if (matrix[f][s + i] == '-')
		{
			matrix[f][s + i] = VISITED;
		}
		else
			break ;
	}
	count++;
}

void	count_under(int	f, int s, int fir_idx)
{
	for (int i = 0; i < fir_idx; i++)
	{
		if (matrix[f + i][s] == '|')
		{
			matrix[f + i][s] = VISITED;
		}
		else
			break ;
	}
	count++;
}

void	search(int fir_idx, int sec_idx)
{
	for (int i = 0; i < fir_idx; i++)
	{
        for (int j = 0; j < sec_idx; j++)
	    {
		    if (matrix[i][j] == 1)
			{
				count_right(i, j, sec_idx);
			}
	    }
	}
}

int main()
{
	int	      fir_idx, sec_idx;
    string    floors;

    cin >> fir_idx >> sec_idx;
	for (int i = 0; i < fir_idx; i++)
	{
        cin >> floors;
        for (int j = 0; j < sec_idx; j++)
	    {
		    matrix[i][j] = floors[j];
	    }
	}
	search(fir_idx, sec_idx);
	cout << count;
	return (0);
}
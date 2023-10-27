#include <string.h>
#include <list>
#include <iostream>
#include <istream>
#include <string>
using namespace std;

typedef struct s_balloon
{
	int	num;
	int	memo;
}	t_balloon;

int	main()
{
	int	n, memo, index;
	t_balloon	balloon, temp_balloon;
	list <t_balloon> balloons;
	list <t_balloon>::iterator iter;

	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	index = 1;
	while (index <= n)
	{
		cin >> memo;
		balloon.memo = memo;
		balloon.num = index;
		balloons.push_back(balloon);
		index++;
	}
	iter = balloons.begin();
	while (!balloons.empty())
	{
		memo = (*iter).memo;
		cout << (*iter).num << '\n';
		iter = balloons.erase(iter);
		if (memo > 0)
		{
			while (memo - 1 > 0)
			{
				if (iter == balloons.end())
					iter++;
				iter++;
				if (iter == balloons.end())
					iter++;
				memo--;
			}
		}
		else if (memo < 0)
		{
			while (memo + 1 < 0)
			{
				if (iter == balloons.begin())
				{
					iter = balloons.end();
					iter--;
				}
				else
					iter--;
				memo++;
			}
		}
	}
	return (0);
}
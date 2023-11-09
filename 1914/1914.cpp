#include <iostream>
#include <list>

std::list<int>	a, b, c;

void	hanoi(int n, std::list<int> from, std::list<int> temp, std::list<int> to)
{
	if (!from.empty())
	{
		to.push_front(from.front());
		std::cout << from.front() << std::endl;
		from.pop_front();
	}
	if (n == 1)
		return ;
	if (!temp.empty())
	{
		temp.push_front(to.front());
		std::cout << from.front() << std::endl;
		temp.pop_front();
	}
	hanoi(n - 1, from, to, temp);
	hanoi(n - 1, temp, from, to);
}

int	main()
{
	int	n;

	std::cin >> n;
	for (int i = 1; i <= n; i++)
		a.push_back(i);
	for (int i = 1; i <= n; i++)
	{
		std::cout << a.front() << ' ';
		a.pop_front();
	}
	for (int i = 1; i <= n; i++)
		a.push_back(i);
	std::cout << std::endl;
	hanoi(n, a, b, c);
	// for (int i = 1; i <= n; i++)
	// {
	// 	std::cout << c.front() << ' ';
	// 	c.pop_front();
	// } 
}
#include <string.h>
#include <list>
#include <iostream>
#include <istream>
#include <string>
using namespace std;

int	main()
{
	char					letter, flag;
	int						len, flag_times, i;
	string					typed;	
	list<char> 				line;
	list<char>::iterator	iter;

	ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin >> typed;
	len = 0;
	while (typed[len])
	{
		letter = typed[len];
		line.push_back(letter);
		len++;
	}
	cin >> flag_times;
	iter = line.end();//초기 커서는 맨 오른쪽
	while (flag_times > 0)
	{
		cin >> flag;
		i = 2;
		if (flag == 'L' && iter != line.begin())//커서 왼쪽으로 한칸
		{
			iter--;
		}
		else if (flag == 'D' && iter != line.end())// 커서 오른쪽으로 한칸
		{
			iter++;
		}
		else if (flag == 'B' && iter != line.begin())// 커서 왼쪽 문자 삭제(문장의 맨 앞이면 동작X)
		{
			iter--;
			iter = line.erase(iter);
		}
		else if (flag == 'P')// 문자를 커서 왼쪽에 추가
		{
			cin >> letter;
			line.insert(iter, letter);
		}
		flag_times--;
	}
	for (iter = line.begin(); iter != line.end(); iter++)
	{
		cout << *iter;
	}
	cout << '\n';
	return (0);
}
#include <string.h>
#include <list>
#include <iostream>
#include <istream>
#include <string>
using namespace std;

int	main()
{
	int						index, password_times;
	string					password;	
	list<char> 				pw;
	list<char>::iterator	iter;

	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> password_times;
	while (password_times)
	{
		cin >> password;
		iter = pw.end();
		index = 0;
		while (password[index])
		{
			if (password[index] == '<' && pw.size() && iter != pw.begin())//커서 왼쪽으로 한칸
			{
				iter--;
			}
			else if (password[index] == '>' && pw.size() && iter != pw.end())// 커서 오른쪽으로 한칸
			{
				iter++;
			}
			else if (password[index] == '-' && pw.size() && iter != pw.begin())// 커서 왼쪽 문자 삭제(문장의 맨 앞이면 동작X)
			{
				iter--;
				iter = pw.erase(iter);
			}
			else if (password[index] != '<' && password[index] != '>' && password[index] != '-')
			{
				iter = pw.insert(iter, password[index]);
				iter++;
			}
			index++;
		}
		for (iter = pw.begin(); iter != pw.end(); iter++)
		{
			cout << *iter;
		}
		cout << '\n';
		password_times--;
		pw.clear();
	}
	return (0);
}
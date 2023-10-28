#include <string.h>
#include <list>
#include <iostream>
#include <istream>
#include <string>
using namespace std;

int	main()
{
	size_t	n, hp, range, dmg, c, now_dmg, final_dmg, elite_zom, heat, index;
	list <size_t> zombies;

	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
    cin >> range;
    cin >> dmg;
    cin >> c;
    now_dmg = dmg;
    heat = 0;
	if (range > n)
	{
		final_dmg = dmg * n;
	}
	else
    	final_dmg = dmg * range;
	elite_zom = 0;
    index = 0;
	while (index < n)
	{
		cin >> hp;
		if (hp > final_dmg)
			elite_zom++;
		zombies.push_back(hp);
		index++;
	}
	if (elite_zom > c)
	{
		cout << "NO";
		return (0);
	}
    while (!zombies.empty())
    {
        if (zombies.front() > now_dmg && c <= 0)
        {
             cout << "NO";
             return (0);
        }
        else if (zombies.front() > now_dmg && c > 0)
        {
			zombies.pop_front();
            c -= 1;
            heat++;
        }
        else if (zombies.front() <= now_dmg)
        {
            if (now_dmg < final_dmg)
                now_dmg += dmg;	
            else if (now_dmg > dmg && (n - heat - index))
            {
                now_dmg -= dmg;
                index++;
            }
            if ((n - heat - index) == 0)
            {
                heat = 0;
                index = 0;
            }
            zombies.pop_front();
        }
		else
			zombies.pop_front();
    }
    cout << "YES";
	return (0);
}
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
    int agents;
    size_t fbi_check;
    string  agent_name;

    agents = 5;
    fbi_check = 0;
    for (int i = 1; i <= agents; i++)
    {
        cin >> agent_name;
        if (agent_name.find("FBI") != agent_name.npos)
        {
            fbi_check++;
            cout << i << ' ';
        }
    }
    if (!fbi_check)
        cout << "HE GOT AWAY!";
    cout << '\n';
    return (0);
}
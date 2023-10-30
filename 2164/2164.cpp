#include <iostream>
#include <list>
using namespace std;

typedef struct s_card
{
    int card_num;
} t_card;

int main()
{
    int cards;                          //카드번호
    t_card  card;                      //카드
    t_card  temp;                      //임시카드
    list<t_card> list;                  //카드팩

    //카드 받아와서 정렬
    cin >> cards;
    for (int i = 1; i <= cards; i++)
    {
        card.card_num = i;
        list.push_back(card);
    }

    //카드 정리
    while (list.size() != 1)
    {
        list.pop_front();
        temp = list.front();
        list.pop_front();
        list.push_back(temp);
    }
	cout << list.front().card_num << '\n';
    return (0);
}
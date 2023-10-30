# 사용언어
C++

# 문제

카드2
-
N장의 카드가 있다. 각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있으며, 1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.

이제 다음과 같은 동작을 카드가 한 장 남을 때까지 반복하게 된다. 

우선, 제일 위에 있는 카드를 바닥에 버린다. 

그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.

예를 들어 N=4인 경우를 생각해 보자. 카드는 제일 위에서부터 1234 의 순서로 놓여있다. 

1을 버리면 234가 남는다. 

여기서 2를 제일 아래로 옮기면 342가 된다. 

3을 버리면 42가 되고, 4를 밑으로 옮기면 24가 된다. 

마지막으로 2를 버리고 나면, 남는 카드는 4가 된다.

N이 주어졌을 때, 제일 마지막에 남게 되는 카드를 구하는 프로그램을 작성하시오.


*입력*
-
첫째 줄에 정수 N(1 ≤ N ≤ 500,000)이 주어진다.



*출력*
-
첫째 줄에 남게 되는 카드의 번호를 출력한다.



해석 및 접근 방식
-
해당 문제는 **가장 위에 있는 카드** 즉 **list** 로나 **queue** 로 보아도 맨 앞의 부분만 값을 없애거나 움직이는것이다.
다음과 같은 동작을 카드가 한 장만 남을 때 까지 하면 된다.
*카드 지우기*, *카드 맨 뒤로 보내기*
본인은 해당 문제를 **list**자료구조를 통해 해결할 것이기에 필요한 문법은 딱 두가지 였다.
*list.pop_front()*, *list.push_back()*
위의 두개의 문법중 두번째인 카드를 맨뒤로 보내는 문법은 해당 카드를 복사해서 뒤에 추가하는 방식으로 구조가 이루어져있기에,
뒤로 복사해 보내고 나서 맨 앞에 복사를 당한 오리지널 카드를 삭제하는 방식으로 코드를 작성했다.



# 풀이

맞은 코드
-

    #include <iostream>
    #include <list>
    using namespace std;
  
    typedef struct s_card
    {
        int card_num;
    } t_card;
  
    int main()
    {
        int cards;                         //카드번호
        t_card  card;                      //카드
        t_card  temp;                      //임시카드
        list<t_card> list;                 //카드팩
  
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



사용 알고리즘 및 자료구조
-
stl의 list 자료 구조를 사용했다.
stl의 list 는 기본적으로 linked list로 이루어져있다고 한다.



참고 자료
-
<https://modoocode.com/177>



출력 및 예시
-



시간 복잡도와 효율
-
O(N)

# 오답노트



틀린 코드
-
없음



리팩토링
-
솔직히 말해서 구조체까지 사용하는건 좀 아닌거 같았다.
그리고 변수명도 너무 구렸다.
temp라는 곳에 추가적으로 저장해서 작업을했는데 해당부분을 거치지 않고도 작업할 수 있다는것을 알게되었다.

    #include <iostream>
    #include <list>
    using namespace std;

    int main()
    {
        int			card_num, card;				//카드 개수, 카드
        list<int> 	card_pack;					//카드팩

        //카드 팩 만들기
        cin >> card_num;
        while (card_num)
    	{
    		card_pack.push_front(card_num);
    		card_num--;
    	}

        //카드 정리
        while (card_pack.size() != 1)
        {
            card_pack.pop_front();
    		card_pack.push_back(card_pack.front());
    		card_pack.pop_front();
        }
    	cout << card_pack.front() << '\n';
        return (0);
    }



시간복잡도와 효율
-
O(N)
같은 O(N) 이지만 56ms 에서 48ms로 줄었다.

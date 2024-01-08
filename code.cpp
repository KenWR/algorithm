#include <iostream>
using namespace std;

int num[12], oper[4]; // +, -, *, /

void    brute_calc(int sum, int operater, int num_idx);
int     operating(int num1, int num2, int operater);

int	main() {
    int N;

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
    cin >> N;
    for (int i = 0; i < N; i++) { // 번호저장
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) { // 연산자 저장
        cin >> oper[i];
    }
    for (int i = 0; i < 4; i++) {
        brute_calc(num[0], i, 1);
    }
}

void    brute_calc(int sum, int operater, int num_idx)
{
    sum = operating(sum, num[i],);
    if (oper[operater])
        brute_calc(sum, int operater, int num_idx)
}

int operating(int num1, int num2, int operater)
{
    if (operater == 0)
        return (num1 + num2);
    if (operater == 1)
        return (num1 - num2);
    if (operater == 2)
        return (num1 * num2);
    if (operater == 3)
        return (num1 / num2);
}

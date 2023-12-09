#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

int	N; 
std::vector<int> possible_numbers;

void	fill_possible_num();
void	say_num();
void	compare_num(int	num, int strike, int ball);
int		count_strike(int input_num, int comp_num);
int		count_ball(int input_num, int comp_num);

int	main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;
	fill_possible_num();
	say_num();
	std::cout << possible_numbers.size();
}

void	fill_possible_num() {
	int	hundreds, tens, units;

	for (int i = 123; i < 999; i++) {
		hundreds = (i / 100) % 10;
		tens = (i / 10) % 10;
		units = i % 10;
		if (hundreds == tens || tens == units || units == hundreds \
		|| tens == 0 || units == 0)
			continue;
		else
			possible_numbers.push_back(i);
	}
}

void	say_num() {
	for (int i = 0; i < N; i++) {
		int	num, strike, ball;
		std::cin >> num >> strike >> ball;
		compare_num(num, strike, ball);
	}
}

void	compare_num(int	num, int strike, int ball) {
	int	count_stk = 0, count_bal = 0;

	for (int i = 0; i < possible_numbers.size(); i++) {
		count_stk = count_strike(num, possible_numbers[i]);
		count_bal = count_ball(num, possible_numbers[i]);
		if (count_stk != strike || count_bal != ball) {
			possible_numbers.erase(possible_numbers.begin() + i);
			i--;
		}
	}
}

int	count_strike(int input_num, int comp_num) {
	int	num_of_strike = 0;
	while (input_num) {
		if (input_num % 10 == comp_num % 10) {
			num_of_strike++;
		}
		input_num /= 10;
		comp_num /= 10;
	}
	return num_of_strike;
}

int	count_ball(int input_num, int comp_num) {
	int	num_of_ball = 0; 
	int	hundreds = (comp_num / 100) % 10;
	int tens = (comp_num / 10) % 10;
	int units = comp_num % 10;

	if (input_num % 10 == hundreds || input_num % 10 == tens) {
		num_of_ball++;
	}
	input_num /= 10;
	if (input_num % 10 == hundreds || input_num % 10 == units) {
		num_of_ball++;
	}
	input_num /= 10;
	if (input_num % 10 == tens || input_num % 10 == units) {
		num_of_ball++;
	}
	return (num_of_ball);
}

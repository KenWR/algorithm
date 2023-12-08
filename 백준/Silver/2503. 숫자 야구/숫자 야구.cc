#include <algorithm>
#include <ios>
#include <iostream>

int	N, baseball, baseball_num[1000];

void	say_num(int swing_times);
void	compare_num(int	num, int strike, int ball);
int	count_strike(int num, int comp_num);
int	count_ball(int num, int hundreds, int tens, int units);
void	output_answer();

int	main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;
	say_num(N);
	output_answer();
}

void	say_num(int swing_times) {
	for (int i = 0; i < N; i++) {
		int	num, strike, ball;
		std::cin >> num >> strike >> ball;
		compare_num(num, strike, ball);
	}
}

void	compare_num(int	num, int strike, int ball) {
	for (int hundreds = 1; hundreds < 10; hundreds++) {
		for (int tens = 1; tens < 10; tens++) {
			if (hundreds == tens) continue;
			for (int units = 1; units < 10; units++) {
				if (hundreds == units || tens == units) continue;
				if ((count_strike(num, (hundreds * 100) + (tens * 10) + units) == strike \
				&& count_ball(num, hundreds, tens, units) == ball)) {
					baseball_num[hundreds * 100 + tens * 10 + units]++;
				}
			}
		}
	}
}

int	count_strike(int num, int comp_num) {
	int	num_of_strike = 0;
	while (num) {
		if (num % 10 == comp_num % 10) num_of_strike++;
		num /= 10;
		comp_num /= 10;
	}
	return num_of_strike;
}

int	count_ball(int num, int hundreds, int tens, int units) {
	int	num_of_ball = 0;
	if (num % 10 == hundreds || num % 10 == tens) num_of_ball++;
	num /= 10;
	if (num % 10 == hundreds || num % 10 == units) num_of_ball++;
	num /= 10;
	if (num % 10 == tens || num % 10 == units) num_of_ball++;
	return num_of_ball;
}

void	output_answer() {
	int	answer = 0;
	for (int hundreds = 1; hundreds < 10; hundreds++) {
		for (int tens = 1; tens < 10; tens++) {
			if (hundreds == tens) continue;
			for (int units = 1; units < 10; units++) {
				if (hundreds  == units || tens  == units) continue;
				
				if (baseball_num[hundreds * 100 + tens * 10 + units] == N) answer++;
			}
		}
	}
	std::cout << answer;
}
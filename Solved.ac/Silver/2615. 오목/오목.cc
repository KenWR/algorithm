#include <ios>
#include <iostream>
#define HEUK 1
#define BAEK 2

int	game_board[19][19];

void	set_board();
void	search_all();
int		find_omok(int y, int x, int color);
int		diagonal_rightunder_leftupper(int y, int x, int color);
int		diagonal_rightupper_leftunder(int y, int x, int color);
int		horizon(int y, int x, int color);
int		virtical(int y, int x, int color);
void	find_head(int y, int x, int color, int omok_type);

int	main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	set_board();
	search_all();
}

void	set_board() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			std::cin >> game_board[i][j];
		}
	}
}

void	search_all() {
	int	omok_type;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			omok_type = 0;
			if (game_board[i][j] == HEUK || game_board[i][j] == BAEK)
				omok_type = find_omok(i, j, game_board[i][j]);
			if (omok_type) {
				find_head(i, j, game_board[i][j], omok_type);
				return;
			}
		}
	}
	std::cout << '0';
}

int	find_omok(int y, int x, int color) {
	if (diagonal_rightupper_leftunder(y, x, color) == 5)
		return (1);
	if (diagonal_rightunder_leftupper(y, x, color) == 5)
		return (2);
	if (virtical(y, x, color) == 5)
		return (3);
	if (horizon(y, x, color) == 5)
		return (4);
	return (0);
}


int		diagonal_rightunder_leftupper(int y, int x, int color) {
	int	len = 1;
	for (int i = 1; i < 19; i++) {
		if ((y - i >= 0 && x - i >= 0) && game_board[y - i][x - i] == color)
			len++;
		else
			break;
	}
	for (int i = 1; i < 19; i++) {
		if ((y + i <= 18 && x + i <= 18) && game_board[y + i][x + i] == color)
			len++;
		else
			break;
	}
	return (len);
}

int		diagonal_rightupper_leftunder(int y, int x, int color) {
	int	len = 1;
	for (int i = 1; i < 19; i++) {
		if ((y - i >= 0 && x + i <= 18) && game_board[y - i][x + i] == color)
			len++;
		else
			break;
	}
	for (int i = 1; i < 19; i++) {
		if ((y + i <= 18 && x - i >= 0) && game_board[y + i][x - i] == color)
			len++;
		else
			break;
	}
	return (len);
}

int		horizon(int y, int x, int color) {
	int	len = 1;
	for (int i = 1; i < 19; i++) {
		if ((x - i >= 0) && game_board[y][x - i] == color)
			len++;
		else
		 	break;;
	}
	for (int i = 1; i < 19; i++) {
		if ((x + i <= 18) && game_board[y][x + i] == color)
			len++;
		else
		 	break;
	}
	return (len);
}

int		virtical(int y, int x, int color) {
	int	len = 1;
	for (int i = 1; i < 19; i++) {
		if ((y - i >= 0) && game_board[y - i][x] == color)
			len++;
		else
			break;
	}
	for (int i = 1; i < 19; i++) {
		if ((y + i <= 18) && game_board[y + i][x] == color)
			len++;
		else
			break;
	}
	return (len);
}

void	find_head(int y, int x, int color, int omok_type) {
	int	i = 0;
	if (omok_type == 1) {// /\|-
		while (game_board[y + i][x - i] == color && y + i <= 18 && x - i >= 0) {
			i++;
		}
		i--;
		std::cout << color << '\n' << y + i +1 << ' ' << x - i + 1;
	}
	else if (omok_type == 2) {
		while (game_board[y - i][x - i] == color && x - i >= 0 && y - i >= 0) {
			i++;
		}
		i--;
		std::cout << color << '\n' << y - i + 1 << ' ' << x + i + 1;
	}
	else if (omok_type == 3) {
		while (game_board[y - i][x] == color && y - i >= 0) {
			i++;
		}
		i--;
		std::cout << color << '\n' << y - i + 1 << ' ' << x + 1;
	}
	else if (omok_type == 4) {
		while (game_board[y][x - i] == color && x - i >= 0) {
			i++;
		}
		i--;
		std::cout << color << '\n' << y + 1 << ' ' << x - i + 1;
	}
}
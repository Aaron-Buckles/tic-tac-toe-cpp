#include <iostream>
#include "TicTacToe.cpp"

void print_welcome_text()
{
	std::cout << "Welcome to Tic Tac Toe (C++ edition)" << std::endl;

}

char current_player(TicTacToe game)
{
	return game.currentPlayer == Player::X ? 'X' : 'O';
}

int main()
{
	print_welcome_text();
	TicTacToe game;
	std::cout << "The current player is " << current_player(game) << std::endl;

	std::cout << "Can make move at 2: " << game.can_make_move(1) << std::endl;
	game.make_move(game.currentPlayer, 1);
	std::cout << "Can make move at 2: " << game.can_make_move(1) << std::endl;

	return 0;
}
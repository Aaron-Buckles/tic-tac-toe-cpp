#include "../include/TicTacToe.h"

TicTacToe::TicTacToe() : currentPlayer(Player::X) {}

TicTacToe::~TicTacToe() {}

bool TicTacToe::can_make_move(int index)
{
	int x = index % boardSize;
	int y = index / boardSize;
	return board[y][x] == Player::None;
}

void TicTacToe::make_move(Player p, int index)
{
	int x = index % boardSize;
	int y = index / boardSize;
	board[y][x] = p;
}
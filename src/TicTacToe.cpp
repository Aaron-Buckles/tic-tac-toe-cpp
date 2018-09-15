#include "../include/TicTacToe.h"

TicTacToe::TicTacToe() : currentPlayer(Player::X) {}

TicTacToe::~TicTacToe() {}

Player TicTacToe::player_on_spot(int x, int y)
{
	return board[y][x];
}

bool TicTacToe::is_spot_empty(int index)
{
	if (index >= BOARD_SIZE*BOARD_SIZE) return false;

	int x = index % BOARD_SIZE;
	int y = index / BOARD_SIZE;
	return board[y][x] == Player::None;
}

void TicTacToe::make_move(int index)
{
	int x = index % BOARD_SIZE;
	int y = index / BOARD_SIZE;
	board[y][x] = currentPlayer;
}

void TicTacToe::next_turn()
{
	if (currentPlayer == Player::X)
		currentPlayer = Player::O;
	else
		currentPlayer = Player::X;
}

bool TicTacToe::is_game_over(int lastMove)
{
	int x = lastMove % BOARD_SIZE;
	int y = lastMove / BOARD_SIZE;

	if (won_horizontal(y)) return true;
	if (won_vertical(x)) return true;
	if (won_diagonal()) return true;

	if (is_board_full())
	{
		draw = true;
		return true;
	}

	return false;
}

bool TicTacToe::won_horizontal(int y)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (board[y][i] != currentPlayer) return false;
	}
	return true;
}

bool TicTacToe::won_vertical(int x)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (board[i][x] != currentPlayer) return false;
	}
	return true;
}

bool TicTacToe::won_diagonal()
{
	bool downRightDiagonal = true;
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (board[i][i] != currentPlayer)
		{
			downRightDiagonal = false;
			break;
		}
	}
	if (downRightDiagonal) return true;

	// up-right diagonal
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (board[BOARD_SIZE - i - 1][i] != currentPlayer)
		{
			return false;
		}
	}
	return true;
}

bool TicTacToe::is_board_full()
{
	for (int x = 0; x < BOARD_SIZE; ++x)
	{
		for(int y = 0; y < BOARD_SIZE; ++y)
		{
			if (board[y][x] == Player::None)
			{
				return false;
			}
		}
	}
	return true;
}
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

enum class Player { X, O, None };

class TicTacToe
{
	Player board[3][3] = { { Player::None, Player::None, Player::None },
			  			   { Player::None, Player::None, Player::None },
			  			   { Player::None, Player::None, Player::None } };
	const int boardSize = 3;
	
public:
	Player currentPlayer;

	TicTacToe();
	~TicTacToe();

	bool can_make_move(int index);
	void make_move(Player p, int index);

};

#endif
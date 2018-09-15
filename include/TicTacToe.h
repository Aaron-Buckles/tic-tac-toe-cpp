#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

enum class Player { X, O, None };

class TicTacToe
{
	Player board[3][3] = { { Player::None, Player::None, Player::None },
			  			   { Player::None, Player::None, Player::None },
			  			   { Player::None, Player::None, Player::None } };

	bool won_horizontal(int y);
	bool won_vertical(int x);
	bool won_diagonal();
	bool is_board_full();
	
public:
	const int BOARD_SIZE = 3;
	Player currentPlayer;
	bool draw = false;

	TicTacToe();
	~TicTacToe();

	Player player_on_spot(int x, int y);
	bool is_spot_empty(int index);
	void make_move(int index);
	void next_turn();
	bool is_game_over(int lastMove);

};

#endif
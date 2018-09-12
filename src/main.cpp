#include <iostream>
#include "TicTacToe.cpp"

void print_welcome_text()
{
	std::cout << "Welcome to Tic Tac Toe (C++ edition)" << std::endl;

}

char player_to_char(Player p)
{
	return p == Player::X ? 'X' : 'O';
}

void draw_spot(TicTacToe game, int x, int y)
{
	int index = (y * game.BOARD_SIZE) + x;

	// The contents of the spot (either the index or the Player)
	if (game.is_spot_empty(index))
	{
		std::cout << index + 1;
	}
	else
	{
		std::cout << player_to_char(game.player_on_spot(x, y));
	}

	if (x == game.BOARD_SIZE - 1)
	{
		std::cout << "\n";
	}
	else
	{
		std::cout << "|";
	}
}

void draw_board(TicTacToe game)
{
	for (int y = 0; y < game.BOARD_SIZE; ++y)
	{
		for (int x = 0; x < game.BOARD_SIZE; ++x)
		{
			draw_spot(game, x, y);
		}

		for (int i = 0; i < game.BOARD_SIZE; ++i)
			std::cout << "--";
		std::cout << "\n";
	}
}

void print_game_over(TicTacToe game)
{
	draw_board(game);

	std::cout << "Game over" << std::endl;

	if (game.draw)
	{
		std::cout << "Draw" << std::endl;
	}
	else
	{
		std::cout << player_to_char(game.currentPlayer) << " wins!" << std::endl;
	}
}

int main()
{
	print_welcome_text();

	TicTacToe game;
	int move = 0;

	while (true)
	{
		draw_board(game);
		while (true)
		{
			std::cout << "Player " << player_to_char(game.currentPlayer) << ": ";
			std::cin >> move;
			--move;

			if (game.is_spot_empty(move))
			{
				game.make_move(move);
				break;
			}
			else
			{
				std::cout << "Invalid move... Try again" << std::endl;
			}
		}

		if (game.is_game_over(move))
		{
			print_game_over(game);
			break;
		}

		game.next_turn();		
	}

	return 0;
}
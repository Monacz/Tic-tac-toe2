#pragma once

#include "Board.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class Game
{
public:
	Game() = default;
	explicit Game(std::size_t dimension);
	~Game() = default;

	void playGame();

private:
	std::size_t dimension;

	void instructions();
	char opponent(Player* player);
	char whatGameWillBe();
	char game(Board& board, Player* player1, Player* player2);
	void announceWinner(char winner, Player* player1, Player* player2);

	static constexpr char X = 'X';
	static constexpr char O = 'O';
	static constexpr char EMPTY = ' ';
	static constexpr char NO_ONE = 'N';
};

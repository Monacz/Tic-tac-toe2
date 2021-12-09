#pragma once

#include "Player.h"

class HumanPlayer: public Player
{
public:
	HumanPlayer();
	~HumanPlayer() = default;

	Cell makeMove(Board& board) override;

private:

	//Is player doing the first move
	void isFirstMove();
	//Just a helpful func
	char askYesNo(std::string&& question);

};
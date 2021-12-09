#pragma once

#include "Board.h"
#include "Cell.h"

//Base abstract class for HumanPlayer and ComputerPlayer
class Player
{
public:
	Player() = default;
	Player(char symbol);
	virtual ~Player() = default;

	//Making movement (to override)
	virtual Cell makeMove(Board& board) = 0;
	char getSymbol();

protected:
	char playerSymbol;
};
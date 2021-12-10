#pragma once

#include "Player.h"

class ComputerPlayer : public Player
{
public:
	ComputerPlayer(char symbol);
	~ComputerPlayer() = default;

	Cell makeMove(Board board) override;
};

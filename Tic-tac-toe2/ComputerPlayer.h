#pragma once

#include "Player.h"

class ComputerPlayer : public Player
{
public:
	ComputerPlayer() = default;
	explicit ComputerPlayer(char symbol);
	~ComputerPlayer() = default;

	Cell makeMove(Board board) override;
};

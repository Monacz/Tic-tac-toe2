#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Cell.h"

class Board
{
public:
	Board(std::size_t numSquares);
	~Board() = default;

	void displayBoard();
	//Is movement legal?
	bool isLegal(Cell movement);
	//does the move win 
	bool isWinnerMovement(Cell movement, char piece);
	//Do movement
	void setMovement(Cell movement, char piece);
	//size of board
	std::size_t size();

private:
	std::vector<std::vector<char>> board;
	std::size_t numSquares;

	static constexpr char EMPTY = ' ';
};


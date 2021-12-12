#include "Board.h"



Board::Board(std::size_t numSquares):numSquares(numSquares),
board(numSquares,std::vector<char>(numSquares, EMPTY))
{

}

void Board::displayBoard()
{
    std::cout << std::endl << "           ";
    for (size_t i = 0; i < numSquares; ++i)
    {
        std::cout << i << "     ";
    }
    std::string someString = std::string(numSquares * 6, '-');
    std::cout << std::endl << "        " + someString + "-" << std::endl;
    for (size_t i = 0; i < numSquares; ++i)
    {
        std::cout << "      "<< i <<" ";
        for (size_t j = 0; j < numSquares; ++j)
        {
            std::cout << "|  " << board[i][j] << "  ";
        }
        std::cout << "|";
        std::cout << std::endl << "        " + someString + "-"<< std::endl;
    }
    std::cout << "\n\n";
}

bool Board::isLegal(Cell movement)
{
    return  movement.x < numSquares && movement.x >= 0 && movement.y < numSquares
        && movement.y >= 0 && (board[movement.x][movement.y] == EMPTY);
}

bool Board::isWinnerMovement(Cell movement, char piece)
{
    bool isWinner = true;
    for (size_t i = 0; i < numSquares; ++i)
    {
        if (board[movement.x][i] != piece)
        {
            isWinner = false;
        }

    }
    if (isWinner)
    {
        return isWinner;
    }

    isWinner = true;
    for (size_t i = 0; i < numSquares; ++i)
    {
        if (board[i][movement.x] != piece)
        {
            isWinner = false;
        }

    }
    if (isWinner)
    {
        return isWinner;
    }
    
    if (movement.x == movement.y)
    {
        isWinner = true;
        for (size_t i = 0; i < numSquares; ++i)
        {
                if (board[i][i] != piece)
                {
                    isWinner = false;
                }
        }
        if (isWinner)
        {
            return isWinner;
        }
    }

    if (movement.x + movement.y == numSquares - 1)
    {
        isWinner = true;
        for (size_t i = 0; i < numSquares; ++i)
        {
            for (size_t j = 0; j < numSquares; ++j)
            {
                if (i + j == numSquares - 1 && board[i][j] != piece)
                {
                    isWinner = false;
                }
            }

        }
        if (isWinner)
        {
            return isWinner;
        }
    }
    return isWinner;
}

void Board::setMovement(Cell movement, char piece)
{
    if (isLegal(movement))
    {
        board[movement.x][movement.y] = piece;
    }
}

void Board::undoMovement(Cell movement)
{
    board[movement.x][movement.y] = EMPTY;
}

std::size_t Board::size()
{
    return numSquares;
}
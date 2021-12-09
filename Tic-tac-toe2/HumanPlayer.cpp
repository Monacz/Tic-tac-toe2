#include "HumanPlayer.h"


HumanPlayer::HumanPlayer()
{
    isFirstMove();
}

Cell HumanPlayer::makeMove(Board& board)
{
    Cell movement;
   
    std::cout << std::endl  << "Write cell you want to set in like '1 2': ";
    std::cin >> movement.x >> movement.y;
    std::cout << std::endl;
    return movement;
}

void HumanPlayer::isFirstMove()
{
    char go_first = askYesNo("Do you require the first move?");
    if (go_first == 'y')
    {
        std::cout << "\nThen take the first move.  You will need it.\n";
        playerSymbol = 'X';
    }
    else
    {
        std::cout << "\nYour bravery will be your undoing... I will go first.\n";
        playerSymbol = 'O';
    }
}

char HumanPlayer::askYesNo(std::string&& question)
{
    char response;
    do
    {
        std::cout << question << " (y/n): ";
        std::cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}

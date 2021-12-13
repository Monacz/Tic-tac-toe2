#include "ComputerPlayer.h"

#include <random>
#include <ctime>
#include <thread>

ComputerPlayer::ComputerPlayer(char symbol) :Player(symbol)
{

}

Cell ComputerPlayer::makeMove(Board board)
{
    //take a sleep
    std::this_thread::sleep_for(std::chrono::seconds(3));

    Cell move;
    bool found = false;

    //if computer can win on next move, that’s the move to make
    for (size_t i = 0; i < board.size(); ++i)
    {
        for (size_t j = 0; j < board.size(); ++j)
        {
            move = { i,j };
            if (board.isLegal(move))
            {
                //try move
                board.setMovement(move, playerSymbol);
                //test for winner
                found = board.isWinnerMovement(move, playerSymbol);
                //undo move
                board.undoMovement(move);
            }
            if (found)
            {
                break;
            }
        }
        if (found)
        {
            break;
        }
    }


    //otherwise, if opponent can win on next move, that's the move to make
    if (!found)
    {
        
        char human = (playerSymbol == 'X') ? 'O' : 'X';

        for (size_t i = 0; i < board.size(); ++i)
        {
            for (size_t j = 0; j < board.size(); ++j)
            {
                move = { i,j };
                if (board.isLegal(move))
                {
                    //try move
                    board.setMovement(move, human);
                    //test for winner
                    found = board.isWinnerMovement(move, human);
                    //undo move
                    board.undoMovement(move);
                }
                if (found)
                {
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
    }

    //otherwise, moving to the best open square is the move to make
    if (!found)
    {
        std::size_t i = 0;

        const std::vector<std::vector<std::size_t>> bestMoves{ {0, 0}, { 0, board.size() - 1 },
            { board.size() - 1 , board.size() - 1 }, { board.size() - 1 , 0}, {board.size() / 2, board.size() / 2 } };
        //pick best open square
        while (!found && i < bestMoves.size())
        {
            move = { bestMoves[i][0], bestMoves[i][1] };
            if (board.isLegal(move))
            {
                found = true;
            }
            ++i;
        }
    }

    if (!found)
    {
        int A = 0, B = board.size() - 1;
        std::mt19937 gen(time(0));
        std::uniform_int_distribution<size_t> uid(A, B);
        move = { uid(gen),uid(gen) };

    }
    return move;
}


#include "Game.h"
#include <memory>

void Game::instructions()
{
    std::cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
    std::cout << "Make your move known by entering two numbers, 0 - 8.  The number\n";
    std::cout << "corresponds to the desired board position, as illustrated:\n\n";

    std::cout << "          0   1   2";
    std::cout << "\n";
    std::cout << "        -------------\n";
    std::cout << "      0 |   |   |   |\n";
    std::cout << "        -------------\n";
    std::cout << "      1 |   |   |   |\n";
    std::cout << "        -------------\n";
    std::cout << "      2 |   |   |   |\n";
    std::cout << "        -------------\n\n";

    std::cout << "The battle is about to begin.\n\n";
}

char Game::whatGameWillBe()
{
    char someChar;
    std::cout << std::endl;
    std::cout << "Do you want AI with AI (write A) or Human with AI?(write H): ";
    std::cin >> someChar;
    while (someChar != 'A' && someChar != 'H')
    {
        std::cout << "Do you want AI with AI (write A) or Human with AI?(write H): ";
        std::cin >> someChar;
    }
    std::cout << std::endl;
    return someChar;
}

char Game::opponent(Player& player)
{
    if (player.getSymbol() == 'X')
    {
        return 'O';
    }
    else
    {
        return 'X';
    }
}

char Game::game(Board& board, Player& player1, Player& player2)
{
    char winner = NO_ONE;
    char turn = X;
    Cell move;
    board.displayBoard();
    while (winner == NO_ONE)
    {
        if (turn == player1.getSymbol())
        {

            std::cout << std::endl << "First's Player turn:" << std::endl;
            move = player1.makeMove(board);
            while (!board.isLegal(move))
            {
                move = player1.makeMove(board);
            }
            board.setMovement(move, player1.getSymbol());
            if (board.isWinnerMovement(move, player1.getSymbol()))
            {
                winner = player1.getSymbol();
            }
            turn = player2.getSymbol();
        }
        else
        {
            std::cout << std::endl << "Second's Player turn:" << std::endl;
            move = player2.makeMove(board);
            while (!board.isLegal(move))
            {
                move = player2.makeMove(board);
            }
            board.setMovement(move, player2.getSymbol());
            if (board.isWinnerMovement(move, player2.getSymbol()))
            {
                winner = player2.getSymbol();
            }
            turn = player1.getSymbol();
        }
        board.displayBoard();
    }
    return winner;
}

void Game::announceWinner(char winner, Player& player1, Player& player2)
{
    if (winner == player1.getSymbol())
    {
        std::cout << "Player1's won!\n";
    }
    if (winner == player2.getSymbol())
    {
        std::cout << "Player2's won!\n";
    }
    if (winner == NO_ONE)
    {
        std::cout << "Tie!\n";
    }
}

Game::Game(std::size_t dimension): dimension(dimension)
{
}

void Game::playGame()
{
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    char whatGame = whatGameWillBe();
    if (whatGame == 'H')
    {
        player1 = std::make_unique<HumanPlayer>();
        player2 = std::make_unique<ComputerPlayer>(opponent(*player1));
        instructions();
    }
    else 
    {
        player1 = std::make_unique<ComputerPlayer>(X);
        player2 = std::make_unique<ComputerPlayer>(opponent(*player1));
    }
    Board board(dimension);

    char winner = game(board, *player1, *player2);
    announceWinner(winner, *player1, *player2);
}

#include "Class.h"

int main()
{
    std::string name1, name2;
    int row, column;
    int x_won, o_won;
    char symbol,TicToeBoard;

    std::cout << "User1, enter your name: \n";
    std::cin >> name1;
    std::cout << "User2, enter your name: \n";
    std::cin >> name2;

    TicTacToe tictac;

    for (int i = 0; i < 8; i++)
    {
        std::cout << name1 << ", enter your row and column: " << "\n";
        std::cin >> row >> column;
        symbol = 'x';
        TicToeBoard = tictac.selectgrid(row, column, symbol);
        tictac.printboard();
        std::cout << name2 << ", enter your row and column: " << "\n";
        std::cin >> row >> column;
        symbol = 'o';
        TicToeBoard = tictac.selectgrid(row, column, symbol);
        tictac.printboard();

        std::pair<int, int> result = tictac.who_won();

        x_won = result.first;
        o_won = result.second;

        if ((x_won==1) || (o_won==1))
        {
            break;
        }
    }
    tictac.printresult(name1, name2, x_won, o_won);
    tictac.printboard();

    return 0;
}
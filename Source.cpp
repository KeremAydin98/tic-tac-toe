#include "Class.cpp"

int main()
{
    std::string name1, name2;
    int row, column;
    int x_won, o_won;
    char symbol;

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
        tictac.selectgrid(row, column, symbol);
        std::cout << name2 << ", enter your row and column: " << "\n";
        std::cin >> row >> column;
        symbol = 'o';
        tictac.selectgrid(row, column, symbol);
        tictac.printboard();

        x_won,o_won=tictac.who_won();
        if (x_won || o_won)
        {
            break;
        }
    }
    tictac.printresult(name1, name2, x_won, o_won);
    tictac.printboard();

    return 0;
}
#include <iostream>
#include <string>
class TicTacToe
{

    char TicTacToeBoard[4][4];

    public:

        TicTacToe();
        char selectgrid(int row, int column, char symbol);
        std::pair<int, int> who_won();
        void printresult(std::string name1, std::string name2, int x_won, int o_won);
        void printboard();



};


#include "Class.h"

TicTacToe::TicTacToe()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            TicTacToeBoard[i][j] = '-';
        }
    }
}

char TicTacToe::selectgrid(int row, int column, char symbol)
{
    TicTacToeBoard[row][column] = symbol;

    return TicTacToeBoard[row][column];
}

std::pair<int,int> TicTacToe::who_won()
{
    int column_x = 0, column_o = 0;
    int row_x = 0, row_o = 0;
    int diagonal_x = 0, diagonal_o = 0;
    int x_won = 0, o_won = 0;
    int z = 3;

    for (int i = 0; i < 4; i++)
    {
        column_x = 0;
        column_o = 0;
        row_x = 0;
        row_o = 0;
        diagonal_x = 0;
        diagonal_o = 0;
   
        for (int j = 0; j < 4; j++) //column and row check
        {
            if (TicTacToeBoard[i][j] == 'x')
            {
                column_x += 1;
            }
            else if (TicTacToeBoard[i][j] == 'o')
            {
                column_o += 1;
            }
            if (TicTacToeBoard[j][i] == 'x')
            {
                row_x += 1;
            }
            else if (TicTacToeBoard[j][i] == 'o')
            {
                row_o += 1;
            }
 
            if ((column_x== 4) || (row_x == 4))
            {
                x_won = 1;
                goto stop;
            }
            else if ((column_o == 4) || (row_o == 4))
            {
                o_won = 1;
                goto stop;
            }
        }
    }
    for (int i = 0; i < 4; i++) //diagonal check
    {
        if (TicTacToeBoard[i][i] == 'x')
        {
            diagonal_x += 1;
            if (diagonal_x == 4)
            {
                x_won = 1;
                goto stop;
            }
        }
        diagonal_x = 0;
        if (TicTacToeBoard[i][i] == 'o')
        {
            diagonal_o += 1;
            if (diagonal_o == 4)
            {
                x_won = 1;
                goto stop;
            }
        }
        diagonal_o = 0;
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (TicTacToeBoard[i][z] == 'x')
        {
            diagonal_x += 1;
            if (diagonal_x == 4)
            {
                x_won = 1;
                goto stop;
            }
        }
        if (TicTacToeBoard[i][z] == 'o')
        {
            diagonal_o += 1;
            if (diagonal_o == 4)
            {
                o_won = 1;
                goto stop;
            }
        }
        z-= 1;
    }
    stop:
    return std::make_pair(x_won, o_won);
}

void TicTacToe::printresult(std::string name1, std::string name2, int x_won, int o_won)
{
    if (x_won == 1)
    {
        std::cout << name1 << " wins!";
    }
    else if (o_won == 1)
    {
        std::cout << name2 << " wins!";
    }
    else
    {
        std::cout << "Draw!";
    }
    std::cout << "\n";
}

void TicTacToe::printboard()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << TicTacToeBoard[i][j] << " ";
        }
        std::cout << "\n";
    }
}

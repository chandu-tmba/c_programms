#include <iostream>
#include <string>
using namespace std;

struct player
{
    int index;
    char symbol;
};

char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

struct player play1;
struct player play2;

void display_board()
{
    cout << "-------\n";
    for (auto i = 0; i < 3; i++)
    {
        for (auto j = 0; j < 3; j++)
        {
            cout << "|";
            cout << board[i][j];
        }
        cout << "|" << endl;
    }
    cout << "-------\n";
}

bool game_finshed()
{
    int row=0, col=0;
    char temp;

    // check for horizantal line
    for (row = 0; row < 3; row++)
    {
        temp = board[row][col];

        for (col = 1; col < 3; col++)
        {
            if ((board[row][col] == ' ') || (temp != board[row][col]))
                break;
        }

        if (col == 3)
        {
            cout << "HOR player(" << temp << ") is winner \n";
            display_board();
            return true;
        }
        col = 0;
    }

    row=0;
    col=0;

    // check for vertical line
    for (col = 0; col < 3; col++)
    {
        temp = board[row][col]; 
        for (row = 1; row < 3; row++)
        {
            if ((board[row][col] == ' ') || (temp != board[row][col]))
                break;
        }

        if (row == 3)
        {
            cout << "VER player(" << temp << ") is winner \n";
            display_board();
            return true;
        }
        row=0;
    }

    row=0;
    col=0;

    temp = board[row][row];

    // check for 1 st diagnoal line
    for (row = 1; row < 3; row++)
    {
        if ((board[row][row] == ' ') || (temp != board[row][row]))
                break;     
    }
    if (row == 3)
    {
        cout << "1ST DAIG player(" << temp << ") is winner \n";
        display_board();
        return true;
    }

    // check for 2 nd diagnoal line
    for (row = 0, col = 2; row < 3, col >= 0; row++, col--)
    {
        if (board[row][col] != ' ')
        {
            if (board[row][col] != board[col][row])
                break;
        }
    }

    if ((row == 3 && col == -1) && (board[row-1][col+1] != ' '))
    {
        cout << "2ND DAIG player(" << board[row-1][col+1] << ") is winner \n";
        display_board();
        return true;
    }
    return false;



}

char switch_player(char ip)
{
    char op = ' ';
    switch (ip)
    {
    case 'X':
        op = 'O';
        break;
    case 'O':
        op = 'X';
        break;
    default:
        break;
    }
    return op;
}

int main()
{
    int id = 0;
    cout << "welcome to Tic-Toe game\n";
    cout << "enter player1 symbol (X/O):";
    cin >> play1.symbol;
    play1.index = ++id;

    cout << "enter player2 symbol:";
    cin >> play2.symbol;
    play2.index = ++id;

    display_board();

    cout << "player1 symbol:" << play1.symbol << " player1 id:" << play1.index << endl;
    cout << "player2 symbol:" << play2.symbol << " player2 id:" << play2.index << endl;

    char sym = 'X';
    int count = 0;


    while(!game_finshed() && count < 9)
    {
        display_board();

        cout << "player(" << sym << ")turn  enter row (1-3) and column (1-3):" << endl;
        int row, col;
        cin >> row >> col;
        --row;
        --col;

        //cout << "index row:" << row << " col:" << col << endl;
        if (board[row][col] == ' ')
        {
            board[row][col] = sym;
        }
        else
        {
            cout << "invlaid input , try again \n";
            continue;
        }

        // switch player
        sym = switch_player(sym);
        count ++;
    }
    if(count == 9)
        cout << "game draw\n";

    return 0;
}

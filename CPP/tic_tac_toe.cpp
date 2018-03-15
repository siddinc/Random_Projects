#include <iostream>
#include <climits>
#include <windows.h>
using namespace std;

void print_board(string board[3][3]);
bool is_victory();
void play_time(string board[3][3]);

int main()
{
    char x;
    while(1)
    {
        cout << "Welcome to TIC-TAC-TOE!" << endl;
        string board[3][3] = {{"0", "1", "2"}, {"3", "4", "5"}, {"6", "7", "8"}};
        print_board(board);
        play_time(board);

        cout << endl;
        cout << "Do you want to exit? (Y/N): ";
        cin >> x;
        if (x == 'Y' || x == 'y')
        {
            return 0;
        }
        system("cls");
    }
    return 0;
}

void print_board(string board[3][3])
{
    cout << endl;
    cout << "     " << "|" << "     " << "|" << "     " << endl;
    cout << "  " << board[0][0] << "  " << "|" << "  " << board[0][1] << "  " << "|" << "  " << board[0][2] << "  " << endl;
    cout << "_____" << "|" << "_____" << "|" << "_____" << endl;

    cout << "     " << "|" << "     " << "|" << "     " << endl;
    cout << "  " << board[1][0] << "  " << "|" << "  " << board[1][1] << "  " << "|" << "  " << board[1][2] << "  " << endl;
    cout << "_____" << "|" << "_____" << "|" << "_____" << endl;

    cout << "     " << "|" << "     " << "|" << "     " << endl;
    cout << "  " << board[2][0] << "  " << "|" << "  " << board[2][1] << "  " << "|" << "  " << board[2][2] << "  " << endl;
    cout << "     " << "|" << "     " << "|" << "     " << endl;
    cout << endl;

}

bool is_victory(string board[3][3])
{
    int c = 0, d = 0;
    string diaL = board[0][0], diaR = board[0][2];//diaL is for left diagonal and diaR is for right diagonal
    for(int i=0; i<3; i++) // to iterate through rows
    {
        if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2] ))// checks in one whole row if the elements of the row are same then returns true
        {
            return 1;
        }
        if((board[0][i] == board[1][i]) && (board[2][i] == board[1][i] ))// checks in one whole column if the elements of the column are same then returns true
        {
            return 1;
        }
        if(board[i][i] == diaL)//increases the val of c by one if the value is equal
        {
            c+=1;
        }
        if(board[i][2-i] == diaR)//increases the val of d by one if the value is equal
        {
            d+=1;
        }
    }
    if(c == 3)// if the value matches 3 times then it is a win case hence return true
    {
        return 1;
    }
    if(d == 3)// if the value matches 3 times then it is a win case hence return true
    {
        return 1;
    }
    return 0;// default case return false
}

void play_time(string board[3][3])
{
    int counter = 1;
    int i, j, n;
    while(counter <= 9)
    {
        cout << "Your turn player X: ";
        cin >> n;
        i = n/3;
        j = n%3;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout << "You entered a character" << endl << "Enter a number between (0 - 8)" << endl;
            cout << "Your turn player X: ";
            cin >> n;
            i = n/3;
            j = n%3;
        }

        while(board[i][j] == "O" || board[i][j] == "X")
        {
            cout<< "Sorry! That space is already taken" << endl;
            cout << "Your turn player X: ";
            cin >>n;
            i = n/3;
            j = n%3;
        }
        board[i][j] = "X";

        system("cls");
        print_board(board);

        if(is_victory(board) == 1)
        {
            cout << "Player X wins. Congratulations!" << endl;
            break;
        }
        counter += 1;

        if(counter < 9)
        {
            cout << "Your turn player O: ";
            cin >> n;
            i = n/3;
            j = n%3;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                cout << "You entered a character" << endl << "Enter a number between (0 - 8)" << endl;
                cout << "Your turn player O: ";
                cin >> n;
                i = n/3;
                j = n%3;
            }

            while(board[i][j] == "X" || board[i][j] == "O")
            {
                cout<< "Sorry! That space is already taken" << endl;
                cout << "Your turn player O: ";
                cin >>n;
                i = n/3;
                j = n%3;
            }
            board[i][j] = "O";

            system("cls");
            print_board(board);

            if(is_victory(board) == 1)
            {
                cout << "Player O wins. Congratulations!" << endl;
                break;
            }
            counter += 1;
        }
    }
    if(counter > 9)
    {
        cout << "Its a draw!";
    }
}

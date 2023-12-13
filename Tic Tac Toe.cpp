#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void displayBoard(char board[][3])
{
    cout << "Welcome to the Tic Tac Toe game!\n";
    cout << "1"<<"|"<<"2"<<"|"<<"3"<<endl;
    cout << "4"<<"|"<<"5"<<"|"<<"6"<<endl;
    cout << "7"<<"|"<<"8"<<"|"<<"9"<<endl;
    cout << "\nEnter the position that you want to place your mark.\n";
    cout << board[0][0]<<" |"<<board[0][1]<<" |"<<board[0][2]<<endl;
    cout << "--|--|--\n";
    cout << board[1][0]<<" |"<<board[1][1]<<" |"<<board[1][2]<<endl;
    cout << "--|--|--\n";
    cout << board[2][0]<<" |"<<board[2][1]<<" |"<<board[2][2]<<endl;
}

bool PlayerWin(char board[][3], char Player)
{
    if(board[0][0] == Player && board[0][1] == Player && board[0][2] == Player) {return true;}
    else if(board[1][0] == Player && board[1][1] == Player && board[1][2] == Player) {return true;}
    else if(board[2][0] == Player && board[2][1] == Player && board[2][2] == Player) {return true;}
    else if(board[0][0] == Player && board[1][0] == Player && board[2][0] == Player) {return true;}
    else if(board[0][1] == Player && board[1][1] == Player && board[2][1] == Player) {return true;}
    else if(board[0][2] == Player && board[1][2] == Player && board[2][2] == Player) {return true;}
    else if(board[0][0] == Player && board[1][1] == Player && board[2][2] == Player) {return true;}
    else if(board[0][2] == Player && board[1][1] == Player && board[2][0] == Player) {return true;}
    else {return false;}
    
}

bool RobotWin(char board[][3], char robot)
{
    if(board[0][0] == robot && board[0][1] == robot && board[0][2] == robot) {return true;}
    else if(board[1][0] == robot && board[1][1] == robot && board[1][2] == robot) {return true;}
    else if(board[2][0] == robot && board[2][1] == robot && board[2][2] == robot) {return true;}
    else if(board[0][0] == robot && board[1][0] == robot && board[2][0] == robot) {return true;}
    else if(board[0][1] == robot && board[1][1] == robot && board[2][1] == robot) {return true;}
    else if(board[0][2] == robot && board[1][2] == robot && board[2][2] == robot) {return true;}
    else if(board[0][0] == robot && board[1][1] == robot && board[2][2] == robot) {return true;}
    else if(board[0][2] == robot && board[1][1] == robot && board[2][0] == robot) {return true;}
    else {return false;}
}

void robotMove(char board[][3])
{
    int randrow, randcolumn;
    srand(time(0));

    for(int i=0; i<10; i++)
    {
        randcolumn = rand()%3;
        randrow = rand()%3;
        if(board[randrow][randcolumn] == ' ' && !PlayerWin(board,'O'))
        {
            board[randrow][randcolumn] = 'X';
            break;
        }
    }
    
}

bool isBoardFull(char board[][3])
{
    int count=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j]==' ') {count++;}
        }
    }
    if(count==0 && !PlayerWin(board,'O') && !RobotWin(board,'X')) {
        return true;
    }
    else {return false;}
}


int main()
{
    char command, choice;
    bool play = true;
    
    while(play==true)
    {
        char board[3][3] = {{' ',' ',' '},
                            {' ',' ',' '}, 
                            {' ',' ',' '}};
        while(true){
            displayBoard(board); 
            if(PlayerWin(board,'O')){cout<<"Player Wins!\n";break;}
            else if(isBoardFull(board)){cout << "Tie! The board is full.\n\n\n";break;}
            if(RobotWin(board,'X')){cout<<"Robot Wins!\n";break;}
            else if(isBoardFull(board)){cout << "Tie! The board is full.\n\n\n";break;}
            cin>>command;
            if(command == 'q') {play==false;}
            else 
            {
                switch(command)
                {
                    case '1':
                    if(board[0][0]!='X'){board[0][0] = 'O';}
                    break;
                    case '2':
                    if(board[0][1]!='X'){board[0][1] = 'O';}
                    break;
                    case '3':
                    if(board[0][2]!='X'){board[0][2] = 'O';}
                    break;
                    case '4':
                    if(board[1][0]!='X'){board[1][0] = 'O';}
                    break;
                    case '5':
                    if(board[1][1]!='X'){board[1][1] = 'O';}
                    break;
                    case '6':
                    if(board[1][2]!='X'){board[1][2] = 'O';}
                    break;
                    case '7':
                    if(board[2][0]!='X'){board[2][0] = 'O';}
                    break;
                    case '8':
                    if(board[2][1]!='X'){board[2][1] = 'O';}
                    break;
                    case '9':
                    if(board[2][2]!='X'){board[2][2] = 'O';}
                    break;
                }
            }
            robotMove(board);
        }
        cout<<"Want to play another round?(y/n): ";
        cin >> choice;
        if(choice == 'n' || choice == 'N')
        {
            cout << "Thanks for playing!\n";
            play = false;
        }
        else if(choice == 'y' || choice == 'Y')
        {
            play = true;
        }
    }
    return 0;
}






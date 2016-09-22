//Week 9 Lab Book Submission (Assessment) - Due December 11th 4pm

#include <iostream>
#include <cstdlib> //temp for g++ compiler


char theBoard[3][3] = {
    { '1','2','3', },
    { '4','5','6', },
    { '7','8','9', }
};

char player = 'X';

//EXPLAIN VERY SPECIFICALLY WHAT EACH OF THESE VARIABLES ARE DOING!
int n;
int a; //part of void input, input() 'a'
int i;
int j;


//Make sure the below is actually relevant to each question before I start describing each.
void drawBoard();  //q1 = DONE
void input(); //q2 = DONE
void playerToggle(); //q3 = DONE

char winCheck(); //q4 = DONE
                 //int Main  q1 to q4 = DONE

void someOneWon(); //fdgdfgdfgdfgfg



using namespace std;


void drawBoard()
{

    cout << "This is the tic tac toe board:" << endl << endl;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << " " << theBoard[i][j] << " ";

        }
        cout << endl << endl;
    }
}


void input()
{
    int a;
    cout << player << "'s turn. " << endl << endl << "Press a number from the grid relative to your play: ";
    cin >> a;

    if (a == 1)
    {
        if (theBoard[0][0] == '1')
            theBoard[0][0] = player;
        else
        {
            cout << "Invalid selection, already used!" << endl;
            input();
        }
    }
    else if (a == 2)
    {
        if (theBoard[0][1] == '2')
            theBoard[0][1] = player;
        else
        {
            cout << "Invalid selection, already used!" << endl;
            input();
        }
    }
    else if (a == 3)
    {
        if (theBoard
            [0][2] == '3')
            theBoard
            [0][2] = player;
        else
        {
            cout << "Invalid selection, already used!" << endl;
            input();
        }
    }
    else if (a == 4)
    {
        if (theBoard[1][0] == '4')
            theBoard[1][0] = player;
        else
        {
            cout << "Invalid selection, already used!" << endl;
            input();
        }
    }
    else if (a == 5)
    {
        if (theBoard[1][1] == '5')
            theBoard[1][1] = player;
        else
        {
            cout << "Invalid selection, already used!" << endl;
            input();
        }
    }
    else if (a == 6)
    {
        if (theBoard[1][2] == '6')
            theBoard[1][2] = player;
        else
        {
            cout << "Invalid selection, already used!" << endl;
            input();
        }
    }
    else if (a == 7)
    {
        if (theBoard[2][0] == '7')
            theBoard[2][0] = player;
        else
        {
            cout << "Invalid selection, already used!" << endl;
            input();
        }
    }
    else if (a == 8)
    {
        if (theBoard[2][1] == '8')
            theBoard[2][1] = player;
        else
        {
            cout << "Invalid selection, already used!" << endl;
            input();
        }
    }
    else if (a == 9)
    {
        if (theBoard[2][2] == '9')
            theBoard[2][2] = player;
        else
        {
            cout << "Invalid selection, already used!" << endl;
            input();
        }
    }
}


void playerToggle()
{
    if (player == 'X')
        player = '0';
    else
        player = 'X';
}






char winCheck()
{

    //X
    if (theBoard[0][0] == 'X' && theBoard[0][1] == 'X' && theBoard[0][2] == 'X')
        return 'X';
    if (theBoard[1][0] == 'X' && theBoard[1][1] == 'X' && theBoard[1][2] == 'X')
        return 'X';
    if (theBoard[2][0] == 'X' && theBoard[2][1] == 'X' && theBoard[2][2] == 'X')
        return 'X';

    if (theBoard[0][0] == 'X' && theBoard[1][0] == 'X' && theBoard[2][0] == 'X')
        return 'X';
    if (theBoard[0][1] == 'X' && theBoard[1][1] == 'X' && theBoard[2][1] == 'X')
        return 'X';
    if (theBoard[0][2] == 'X' && theBoard[1][2] == 'X' && theBoard[2][2] == 'X')
        return 'X';

    if (theBoard[0][0] == 'X' && theBoard[1][1] == 'X' && theBoard[2][2] == 'X')
        return 'X';
    if (theBoard[2][0] == 'X' && theBoard[1][1] == 'X' && theBoard[0][2] == 'X')
        return 'X';


    //0
    if (theBoard[0][0] == '0' && theBoard[0][1] == '0' && theBoard[0][2] == '0')
        return '0';
    if (theBoard[1][0] == '0' && theBoard[1][1] == '0' && theBoard[1][2] == '0')
        return '0';
    if (theBoard[2][0] == '0' && theBoard[2][1] == '0' && theBoard[2][2] == '0')
        return '0';
    if (theBoard[0][0] == '0' && theBoard[1][0] == '0' && theBoard[2][0] == '0')
        return '0';
    if (theBoard[0][1] == '0' && theBoard[1][1] == '0' && theBoard[2][1] == '0')
        return '0';
    if (theBoard[0][2] == '0' && theBoard[1][2] == '0' && theBoard[2][2] == '0')
        return '0';

    if (theBoard[0][0] == '0' && theBoard[1][1] == '0' && theBoard[2][2] == '0')
        return '0';
    if (theBoard[2][0] == '0' && theBoard[1][1] == '0' && theBoard[0][2] == '0')
        return '0';

    return '/'; //determines draw,  it just returns that there is no winner, so if there is no winnder and there has been 9 turns taken, we can deduce a draw
}

void someOneWon() {
    char input = 'N';
    
    cout << "Would you like to play another game? [Y/N]" << endl;
    do {
        input = getchar();
        putchar(input);
    } while (input != 'Y' && input != 'N');
    if (input == 'Y')
        return;
    //int main();

    else
        exit(0);
}







int main() {
    n = 0;
    drawBoard();
    while (1)
    {
        n++;
        input();
        drawBoard();
        if (winCheck() == 'X')
        {
            cout << "X WINS THE GAME!!!" << endl;
            someOneWon();
            break;


        }
        else if (winCheck() == '0')
        {
            cout << "0 WINS THE GAME!!!" << endl;
            someOneWon();
            break;

        }
        else if (winCheck() == '/' && n == 9)
        {
            cout << "DRAW!!!" << endl << endl;
            someOneWon();
            break;

        }
        playerToggle();
    }
    cout << endl;
system("pause");
return 0;
}
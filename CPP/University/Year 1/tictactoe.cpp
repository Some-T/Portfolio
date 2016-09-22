#include <iostream>
#include <cstdlib> //temp for g++ compiler

//Below is the variable and its type to hold the 2D array for the tic tac toe board.
char theBoard[3][3] = {
  { '1','2','3', },
  { '4','5','6', },
  { '7','8','9', }
};

char player = 'X'; //This variable defines which player is playing and which element they have selected on the board across two functions. 
//The two variables below increment the array to display and manipulate it on screen across the functions below.
int i; 
int j;


//Declared functions:
void drawBoard();  //Function most relevant to Question 1, it creates and initialises the board.
void input(); //Function most relevant to Question 2, it creates a user interface for the player to select 'X' or '0'
void playerToggle(); //Function most relevant to Question 3, it  creates a game loop which controls the game so each player can go in turn.
char winCheck(); //Function most relevant to Question 4, this function checks which player has won (3 across or diagnol) or whether it is a draw or not.

         
using namespace std;


void drawBoard()
{

  /*The code below draws the 3x3 array in the form of a grid numbers using increments, 
  note also the space indicated to make it presentable, overall creating and initialising the board.*/

  cout << endl << "This is the tic tac toe board:" << endl << endl;

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

  /*The code within this function takes the input from the player in the form of a number 
  then depending which player is playing, '0' or 'X' takes the current character from the variable player (current player)
  and converts it to a number on the board, e.g. player = X so if user presses 1 it allocates the relevant coordinates
  as per the code below to the array relevant to the number 1 thus converting 1 to char X or can be player 0 depending on which 
  player is playing.*/

  int selectArray;
  cout << player << "'s turn. " << endl << endl << "Press a number from the grid relative to your play: ";
  cin >> selectArray;

  if (selectArray == 1)
  {
    if (theBoard[0][0] == '1')
      theBoard[0][0] = player;
    else
    {
      cout << "Invalid selection, already used!" << endl;
      input();
    }
  }
  else if (selectArray == 2)
  {
    if (theBoard[0][1] == '2')
      theBoard[0][1] = player;
    else
    {
      cout << "Invalid selection, already used!" << endl;
      input();
    }
  }
  else if (selectArray == 3)
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
  else if (selectArray == 4)
  {
    if (theBoard[1][0] == '4')
      theBoard[1][0] = player;
    else
    {
      cout << "Invalid selection, already used!" << endl;
      input();
    }
  }
  else if (selectArray == 5)
  {
    if (theBoard[1][1] == '5')
      theBoard[1][1] = player;
    else
    {
      cout << "Invalid selection, already used!" << endl;
      input();
    }
  }
  else if (selectArray == 6)
  {
    if (theBoard[1][2] == '6')
      theBoard[1][2] = player;
    else
    {
      cout << "Invalid selection, already used!" << endl;
      input();
    }
  }
  else if (selectArray == 7)
  {
    if (theBoard[2][0] == '7')
      theBoard[2][0] = player;
    else
    {
      cout << "Invalid selection, already used!" << endl;
      input();
    }
  }
  else if (selectArray == 8)
  {
    if (theBoard[2][1] == '8')
      theBoard[2][1] = player;
    else
    {
      cout << "Invalid selection, already used!" << endl;
      input();
    }
  }
  else if (selectArray == 9)
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

  /* As per the function 'input()' this is a critically used toggle using an if statement, so that 
  it can switch between player 1 and 2 or 'X' and '0'*/

  if (player == 'X')
    player = '0';
  else
    player = 'X';
}






char winCheck()
{


  //The below code checks the entire 2D array to see if 'X' via player input goes horizontally, diagonally or vertically.
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
  //The below checks the diagonal elements of the array for 'X'
  if (theBoard[0][0] == 'X' && theBoard[1][1] == 'X' && theBoard[2][2] == 'X')
    return 'X';
  if (theBoard[2][0] == 'X' && theBoard[1][1] == 'X' && theBoard[0][2] == 'X')
    return 'X';


  //The below code checks the entire 2D array to see if '0' via player input goes horizontally, diagonally or vertically.
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
  //The below checks the diagonal elements of the array for '0'
  if (theBoard[0][0] == '0' && theBoard[1][1] == '0' && theBoard[2][2] == '0')
    return '0';
  if (theBoard[2][0] == '0' && theBoard[1][1] == '0' && theBoard[0][2] == '0')
    return '0';


  //The below 'char' is used to determine the outcome of a draw or not, more so in the function 'int main()'
  return '/'; 
}


/*Most relevant to Question's 1 to 4, the below function and its code therein is the core of the program/game, 
it runs through the four functions above using a while loop and an if - else statement contained within. The if - else
statement checks whether 'X' or '0' has achieved filling in 3 elements in the array horizontally, diagonally or vertically,
by using the winCheck function described above, if it is true for 'X' or '0' then the winner is determined on that basis.
Because the array has a total of 9 elements (3x3 = 9) only a maximum of 9 plays can be achieved, the game/program deduces
a draw on that basis. Whether a draw or 'X' or '0' wins the game/program outputs relevant string text to indicate so.*/

int main() 
       
{
  int count = 0;
  drawBoard();
  while (1)
  {
    count++;
    input();
    drawBoard();
    if (winCheck() == 'X')
    {
      cout << "X WINS THE GAME!!!" << endl;
      break;
    }
    else if (winCheck() == '0')
    {
      cout << "0 WINS THE GAME!!!" << endl;
      break;
    }

    /* The below code determines whether or not it is a draw,
    it does this after 9 turns taken it can deduce a draw. */

    else if (winCheck() == '/' && count == 9)
    {
      cout << "DRAW!!!" << endl << endl;
      break;
    }
    playerToggle();
  }
  cout << endl;
  system("pause");
  return 0;
}
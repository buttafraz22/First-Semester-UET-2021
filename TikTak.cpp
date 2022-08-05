#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
//function prototypes________
void header();
void Board();
void PlayonBoard();
void AssignValue(int digit);
bool checkStatus();
char parseData(string row, int column);
void storegame();
void loadgame();
//Data Structures_________
int const GRID = 3;
char space[GRID][GRID] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
bool tie = false;
char symbol = 'X';
int rows;
int columns;
string name1 = " ";
string name2 = " ";
int count = 0 ;
//Data structures end_________
int main()//main function
{
    system("Color E3");
    header();

    cout << "Enter name of first Player: ";
    getline(cin,name1);
    cout<< "Enter name of second Player: ";
    getline(cin,name2);
    cout<<"Press O to Load Previous game? ";
    char cho1;
    cin>> cho1;
    if (cho1 == 'O')
        loadgame();

    cout<<"*******************************"<<endl;
    cout<<"Player "<<name1<<" will be playing symbol X"<<endl;
    cout<<"Player "<<name2<<" will be playing symbol O"<<endl;
    system("cls");
    
    char cho = ' ';
    while(!checkStatus())
    { 
        header();
        Board();
        PlayonBoard();
        cout<<"Press Y to save and exit.";
        cin>>cho;
        if(cho == 'Y')
            storegame();
        else
            checkStatus();
        count++;
        system("cls");
    }
      header();
      Board();
    if(symbol == 'O' && tie == false)
    {
        cout<<"\t\t"<<"\t\t"<<name1<<" having token [X] IS WINNER!!!!!!!"<<endl;
    }
    else if (symbol == 'X' && tie == false)
    {
        cout<<"\t\t"<<"\t\t"<<name2<<" having token [O] IS WINNER!!!!!!!"<<endl;
    }
    else if (tie == true)
    {
        cout<<"\t\t"<<"\t\t"<<"------DRAW------";
    }
}//end main

void Board()//to display board configuration(default and updated)
{
    cout<<"\t\t"<<"\t\t"<<"    |"<<"    |"<<"    \n";
    cout<<"\t\t"<<"\t\t"<<space[0][0]<<"   |"<<space[0][1]<<"   |"<<space[0][2]<<"\n";
    cout<<"\t\t"<<"\t\t"<<"____|"<<"____|"<<"____\n";
    cout<<"\t\t"<<"\t\t"<<"    |"<<"    |"<<"    \n";
    cout<<"\t\t"<<"\t\t"<<space[1][0]<<"   |"<<space[1][1]<<"   |"<<space[1][2]<<"\n";
    cout<<"\t\t"<<"\t\t"<<"____|"<<"____|"<<"____\n";
    cout<<"\t\t"<<"\t\t"<<"    |"<<"    |"<<"    \n";
    cout<<"\t\t"<<"\t\t"<<space[2][0]<<"   |"<<space[2][1]<<"   |"<<space[2][2]<<"\n";
    cout<<"\t\t"<<"\t\t"<<"    |"<<"    |"<<"    \n";
}
void PlayonBoard()//to take player inputs based on box number they enter
{
    int digit;
    if(symbol == 'X') 
    {
        system("Color E5");
        cout<<"\t\t"<<name1<<" Having Token ["<<symbol<<"] Please Enter your Box Number: ";
        cin >> digit;
    }
    else if (symbol == 'O')
    {
        system("Color E4");
        cout << "\t\t"<<name2 <<" Having token ["<<symbol<< "] Please Enter your Box Number: ";
        cin >> digit;
    }
    AssignValue(digit);
    if(symbol == 'X' && space[rows][columns] != 'X' && space[rows][columns] != 'O')//here we update global symbol variable
    {                                                                              //after each player make their turn.
        space[rows][columns] = 'X';
        symbol = 'O';
    }
    else if(symbol == 'O' && space[rows][columns] != 'X' && space[rows][columns] != 'O')
    {
        space[rows][columns] = 'O';
        symbol = 'X';
    }
    else
    {
        cout <<"\t\t"<< "No Empty Space!!!!"<<endl;
        PlayonBoard();//calling function instead of applying a while loop greatly simplifies our logic
    }
}
void AssignValue(int digit)//this function assigns values to rows and columns globally based on box number the user enters*
{
    if(digit == 1)
    {
        rows = 0;
        columns = 0;
    }
    if(digit == 2)
    {
        rows = 0;
        columns = 1 ;
    }
    if(digit == 3)
    {
        rows = 0;
        columns = 2 ;
    }
    if(digit == 4)
    {
        rows = 1;
        columns = 0 ;
    }
    if(digit == 5)
    {
        rows = 1;
        columns = 1 ;
    }
    if(digit == 6)
    {
        rows = 1;
        columns = 2 ;
    }
    if(digit == 7)
    {
        rows = 2;
        columns = 0 ;
    }
    if(digit == 8)
    {
        rows = 2;
        columns = 1 ;
    }
    if(digit == 9)
    {
        rows = 2;
        columns = 2 ;
    }
    else if (digit < 1 || digit > 9)
    {
        cout<<"\t\t"<<"Move is Invalid!!!"<<endl;
    }
}
bool checkStatus()//to check the status of the game(win/draw)
{
    for(int c = 0 ; c < GRID ; c++)//checking winning conditions
    {      //checking rows                                              //checking columns
        if((space[0][0] == space[c][1] && space[c][0] == space[c][2]) ||(space[0][c] == space[1][c] && space[0][c] == space[2][c]))
        {
            return true;
        }        //checking diagonals and anti diagonals
        else if ((space[0][0] == space [1][1] && space[0][0] == space[2][2]) || (space[0][2] == space[1][1] && space[0][2] == space[2][0]))
        {
            return true;
        }
    }
    for (int i = 0 ; i < GRID ; i++)//checking for empty spaces for tie condition
    {
        for (int j = 0 ; j < GRID ; j++)
        {
            if(space[i][j] == 'X' || space[i][j] == 'O')//this condition checks for draw
            {  
               
               if(count == 9)
                {
                    tie = true ;                                
                    return true;
                }
               else
                return false;
            }
        }
    }
    return false;
}
void header()
{
    cout<<"\t\t"<<"***** *  *****   *****  ***** ***** ***** ***** *****"<<endl;
    cout<<"\t\t"<<"  *   *  *         *    *   * *       *   *   * *"<<endl;
    cout<<"\t\t"<<"  *   *  *         *    *   * *       *   *   * *****"<<endl;
    cout<<"\t\t"<<"  *   *  *         *    ***** *       *   *   * *"<<endl;
    cout<<"\t\t"<<"  *   *  *         *    *   * *       *   *   * *"<<endl;
    cout<<"\t\t"<<"  *   *  *****     *    *   * *****   *   ***** *****"<<endl;
    cout<<"\t\t"<<"*******************************************************"<<endl;
}
void loadgame()
{
   string line;
   fstream file;
   file.open("game.txt",ios::in);
   int i = 0;
   while(!file.eof())
   {
       getline(file,line);
       space[i][0] = parseData(line,1);
       space[i][1] = parseData(line,2);
       space[i][2] = parseData(line,3);
       i++;
   }
   file.close();
}
void storegame()
{
   fstream file;
   file.open("game.txt" , ios::out);
   for(int i = 0; i < 3 ; i++)
   {
       if(i <= 1)
       file<<space[i][0]<<','<<space[i][1]<<','<<space[i][2]<<endl;
      else if (i == 2)
       file<<space[i][0]<<','<<space[i][1]<<','<<space[i][2];
   }
   file.close();
   cout<<"\t\t"<<"\t\t"<<"Save operation successful.";
   abort();
}
char parseData(string row, int column)//to parse comma separated file for loading file into relevant array
{
    int commansCount = 1;
    char item;
    int index = 0;
    while (true)
    {

        char ch = row[index];
        if (ch == '\0')
            return item;
        if (ch == ',')
        {
            commansCount++;
        }
        else if (commansCount == column)
        {
            item = item + item;
        }
        index++;
    }
    return item;
}
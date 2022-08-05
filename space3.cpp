#include <iostream> //header files___________
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
using namespace std;
// Data Structures____
char SMap[27][75]{
    {"#####################################################################"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                           P                                        |"},
    {"|                                                                    |"},
    {"#####################################################################"}};

char initializermenu();   // starter menu
void decreaseAlien();     // decrease alien health on hit with player bullet
bool isWinner();          // check winner
void storeData();         // to store data in file
void loadData();          // to load data in file
void PrintSpace();        // to print maze
void totalScore();        // to increment score
void printStatus();       // to print status of the game as a minibar
void MovePlayerLeft();    // self explanatory
void MovePlayerRight();   // self explanatory
void MoveAlien1();        // self explanatory
void MoveAlien2();        // self explanatory
void MoveAlien3();        // self explanatory
void MoveAlien4();        // self explanatory
void fireSpace();         // to fire player bullets
void moveBullet();        // to move player bullets in loop
void checkWalls();        // status checker function, resets flag values
void Alien1Bomb();        // self explanatory
void Alien2Bomb();        // self explanatory
void Alien3Bomb();        // self explanatory
void Alien4Bomb();        // self explanatory
void Debris();            // self explanatory
void instructions();      // self explanatory
void ScoreIncrease();     // self explanatory
void pause();
void gotoxy(int x, int y) // prints cursor at designated location
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void clearsc() // to clear screen
{
    cout << "Press any key to continue: ";
    getch();
    system("cls");
}
// various counter variables
bool gameRunning = 1;
int score = 0;
int healthCount = 5;
int livesCount = 3;
int PlayerX = 24;     // X Coordinate of Player Character
int PlayerY = 28;     // Y Coordinate of Player Character
int Alien1X = 3;      // X coordinate of Alien 1
int Alien1Y = 55;     // Y coordinate of Alien 1
int Alien2X = 4;      // X coordinate of Alien 2
int Alien2Y = 22;     // Y coordinate of Alien 2
int Alien3X = 7;      // self explanatory
int Alien3Y = 57;     // self explanatory
int Alien4X = 10;     // self explanatory
int Alien4Y = 6;      // self explanatory
int Bomb1X = Alien1X; // self explanatory
int Bomb1Y = Alien1Y; // self explanatory
int Bomb2X = Alien2X; // self explanatory
int Bomb2Y = Alien2Y; // self explanatory
int Bomb3X = Alien3X; // self explanatory
int Bomb3Y = Alien3Y; // self explanatory
int Bomb4X = Alien4X; // self explanatory
int Bomb4Y = Alien4Y; // self explanatory
int PlayerFireX = PlayerX;
int PlayerFireY = PlayerY;
int AlienLive = 0;
int DebrisX = 1 + rand() % 23;
int DebrisY = 1 + rand() % 69;
string Alien1D = "RIGHT"; // flag
int Alien1H = 5;
int Alien2H = 5;
int Alien3H = 5;
int Alien4H = 5;
string Alien2D = "LEFT";  // flag
string Alien3D = "RIGHT"; // flag
string Alien4D = "LEFT";  // flag

string Bomb1Flag = "CLEAR"; // flag
string Bomb2Flag = "CLEAR"; // flag
string Bomb3Flag = "CLEAR"; // flag
string Bomb4Flag = "CLEAR"; // flag

string BulletFlag = "CLEAR"; // flag
bool BulletFire = 0;

string DebrisD = "DOWN";

int main()
{
    srand(time(NULL));
    loadData();
    system("CLS");
    system("COLOR F5");
    while (true)
    {
        char option = ' ';
        do
        {
            option = initializermenu();
            clearsc();
            if (option == '1')
            {
                gotoxy(0, 0);
                PrintSpace();
                gotoxy(PlayerY, PlayerX);
                cout << "P";

                while (livesCount > 0)
                {
                    healthCount = 5;

                    if (GetAsyncKeyState(VK_ESCAPE))
                    {
                        break;
                    }
                    do
                    {
                        gameRunning = 1;
                        if ((isWinner()) && AlienLive == 25)
                        {
                            break;
                        }
                        Sleep(100);
                        MoveAlien1();
                        Alien1Bomb();
                        Alien2Bomb();
                        Alien3Bomb();
                        Alien4Bomb();
                        MoveAlien2();
                        MoveAlien3();
                        MoveAlien4();
                        Debris();
                        ScoreIncrease();
                        checkWalls();
                        printStatus();
                        if (BulletFire)
                            moveBullet();
                        decreaseAlien();
                        if (GetAsyncKeyState(VK_LEFT))
                        {
                            MovePlayerLeft();
                        }
                        if (GetAsyncKeyState(VK_RIGHT))
                        {
                            MovePlayerRight();
                        }
                        if (GetAsyncKeyState(VK_SPACE))
                        {
                            BulletFire = 1;
                        }
                        if (GetAsyncKeyState(VK_CONTROL))
                        {
                           pause();
                        }
                    } while (gameRunning);
                }
                printStatus();
                storeData();
                if (isWinner())
                {
                    break;
                }
                getch();
                system("CLS");
            }
            else if (option == '2')
            {
                instructions();
                clearsc();
            }

        } while (option != '3');
        if (option == '3')
            return 0;
    }
}
void PrintSpace()
{
    for (int x = 0; x < 27; x++)
    {
        for (int c = 0; c < 75; c++)
        {
            cout << SMap[x][c];
        }
        cout << endl;
    }
}
void printStatus()
{
    gotoxy(90, 7);
    cout << "******************" << endl;
    gotoxy(90, 8);
    cout << "* SPACE INVADERS *" << endl;
    gotoxy(90, 9);
    cout << "******************" << endl;
    gotoxy(90, 10);
    cout << "Score: " << score << endl;
    gotoxy(90, 12);
    cout << "Health: " << healthCount << "\n";
    gotoxy(90, 11);
    cout << "Lives: " << livesCount << "\n";
    if (isWinner())
    {
        gotoxy(90, 12);
        cout << "You Won. " << endl;
    }
}
void totalScore()
{
    score++;
}
void MovePlayerLeft()
{
    if (SMap[PlayerX][PlayerY - 1] == ' ' || SMap[PlayerX][PlayerY - 1] == '*') // either the adjacent space is empty
    {                                                                           // or there is bomb in there
        SMap[PlayerX][PlayerY] = ' ';
        gotoxy(PlayerY, PlayerX);
        cout << " ";

        PlayerY = PlayerY - 1;
        SMap[PlayerX][PlayerY] = 'P';
        gotoxy(PlayerY, PlayerX);
        cout << "P";
    }
}
void MovePlayerRight()
{
    if (SMap[PlayerX][PlayerY + 1] == ' ' || SMap[PlayerX][PlayerY + 1] == '*') // either the adjacent space is empty
    {                                                                           // or there is bomb in there
        SMap[PlayerX][PlayerY] = ' ';
        gotoxy(PlayerY, PlayerX);
        cout << " ";

        PlayerY = PlayerY + 1;
        SMap[PlayerX][PlayerY] = 'P';
        gotoxy(PlayerY, PlayerX);
        cout << "P";
    }
}

void MoveAlien1()
{
    if (Alien1H > 0)
    {
        if (Alien1D == "RIGHT")
        {
            if (SMap[Alien1X][Alien1Y + 1] == ' ' || SMap[Alien1X][Alien1Y + 1] == '*') // either the adjacent space is empty
            {                                                                           // or there is bomb in there
                SMap[Alien1X][Alien1Y] = ' ';
                gotoxy(Alien1Y, Alien1X);
                cout << " ";

                Alien1Y = Alien1Y + 1;
                gotoxy(Alien1Y, Alien1X);
                cout << "A";
                // if (SMap[Alien1X][Alien1Y + 1] == '|')
                // Alien1D = "LEFT";
            }
            if (SMap[Alien1X][Alien1Y + 1] == '|')
                Alien1D = "LEFT";
        }
        else if (Alien1D == "LEFT")
        {
            if (SMap[Alien1X][Alien1Y - 1] == ' ' || SMap[Alien1X][Alien1Y - 1] == '*') // either the adjacent space is empty
            {                                                                           // or there is bomb in there
                SMap[Alien1X][Alien1Y] = ' ';
                gotoxy(Alien1Y, Alien1X);
                cout << " ";

                Alien1Y = Alien1Y - 1;
                gotoxy(Alien1Y, Alien1X);
                cout << "A";
                // if (SMap[Alien1X][Alien1Y - 1] == '|')
                // Alien1D = "RIGHT";
            }
            if (SMap[Alien1X][Alien1Y - 1] == '|')
                Alien1D = "RIGHT";
        }
    }
}
void MoveAlien2()
{
    if (Alien2H > 0)
    {
        if (Alien2D == "RIGHT")
        {
            if (SMap[Alien2X][Alien2Y + 1] == ' ' || SMap[Alien2X][Alien2Y + 1] == '*') // either the adjacent space is empty
            {                                                                           // or there is bomb in there
                SMap[Alien2X][Alien2Y] = ' ';
                gotoxy(Alien2Y, Alien2X);
                cout << " ";

                Alien2Y = Alien2Y + 1;
                gotoxy(Alien2Y, Alien2X);
                cout << "A";
                if (SMap[Alien2X][Alien2Y + 1] == '|')
                    Alien2D = "LEFT";
            }
            // if (SMap[Alien2X][Alien2Y + 1] == '|')
            //     Alien2D = "LEFT";
        }
        else if (Alien2D == "LEFT")
        {
            if (SMap[Alien2X][Alien2Y - 1] == ' ' || SMap[Alien2X][Alien2Y - 1] == '*') // either the adjacent space is empty
            {                                                                           // or there is bomb in there
                SMap[Alien2X][Alien2Y] = ' ';
                gotoxy(Alien2Y, Alien2X);
                cout << " ";

                Alien2Y = Alien2Y - 1;
                gotoxy(Alien2Y, Alien2X);
                cout << "A";
                if (SMap[Alien2X][Alien2Y - 1] == '|')
                    Alien2D = "RIGHT";
            }
            // if (SMap[Alien2X][Alien2Y - 1] == '|')
            //     Alien2D = "RIGHT";
        }
    }
}

void MoveAlien3()
{
    if (Alien3H > 0)
    {
        if (Alien3D == "RIGHT")
        {
            if (SMap[Alien3X][Alien3Y + 1] == ' ' || SMap[Alien3X][Alien3Y + 1] == '*') // either the adjacent space is empty
            {                                                                           // or there is bomb in there
                SMap[Alien3X][Alien3Y] = ' ';
                gotoxy(Alien3Y, Alien3X);
                cout << " ";

                Alien3Y = Alien3Y + 1;
                gotoxy(Alien3Y, Alien3X);
                cout << "A";
                if (SMap[Alien3X][Alien3Y + 1] == '|')
                    Alien3D = "LEFT";
            }
            // if (SMap[Alien3X][Alien3Y + 1] == '|')
            //     Alien3D = "LEFT";
        }
        else if (Alien3D == "LEFT")
        {
            if (SMap[Alien3X][Alien3Y - 1] == ' ' || SMap[Alien3X][Alien3Y - 1] == '*') // either the adjacent space is empty
            {                                                                           // or there is bomb in there
                SMap[Alien3X][Alien3Y] = ' ';
                gotoxy(Alien3Y, Alien3X);
                cout << " ";

                Alien3Y = Alien3Y - 1;
                gotoxy(Alien3Y, Alien3X);
                cout << "A";
                if (SMap[Alien3X][Alien3Y - 1] == '|')
                    Alien3D = "RIGHT";
            }
            // if (SMap[Alien3X][Alien3Y - 1] == '|')
            //     Alien3D = "RIGHT";
        }
    }
}
void MoveAlien4()
{
    if (Alien4H > 0)
    {
        if (Alien4D == "RIGHT")
        {
            if (SMap[Alien4X][Alien4Y + 1] == ' ' || SMap[Alien4X][Alien4Y + 1] == '*') // either the adjacent space is empty
            {                                                                           // or there is bomb in there
                SMap[Alien4X][Alien4Y] = ' ';
                gotoxy(Alien4Y, Alien4X);
                cout << " ";

                Alien4Y = Alien4Y + 1;
                gotoxy(Alien4Y, Alien4X);
                cout << "A";
                if (SMap[Alien4X][Alien4Y + 1] == '|')
                    Alien4D = "LEFT";
            }
            // if (SMap[Alien4X][Alien4Y + 1] == '|')
            //     Alien4D = "LEFT";
        }
        else if (Alien4D == "LEFT")
        {
            if (SMap[Alien4X][Alien4Y - 1] == ' ' || SMap[Alien4X][Alien4Y - 1] == '*') // either the adjacent space is empty
            {                                                                           // or there is bomb in there
                SMap[Alien4X][Alien4Y] = ' ';
                gotoxy(Alien4Y, Alien4X);
                cout << " ";

                Alien4Y = Alien4Y - 1;
                gotoxy(Alien4Y, Alien4X);
                cout << "A";
                if (SMap[Alien4X][Alien4Y - 1] == '|')
                    Alien4D = "RIGHT";
            }
            // if (SMap[Alien4X][Alien4Y - 1] == '|')
            //     Alien4D = "RIGHT";
        }
    }
}
void Alien1Bomb() // Bombs Of Alien 1
{

    if (Bomb1Flag == "CLEAR")
    {
        if (SMap[Bomb1X + 1][Bomb1Y] == ' ' || SMap[Bomb1X + 1][Bomb1Y] == 'P')
        {
            SMap[Bomb1X][Bomb1Y] = ' ';
            gotoxy(Bomb1Y, Bomb1X);
            cout << " ";

            Bomb1X++;
            gotoxy(Bomb1Y, Bomb1X);
            cout << "*";
            gotoxy(Bomb1Y, Bomb1X - 1);
            cout << " ";
            if (Bomb1X == PlayerX && Bomb1Y == PlayerY)
            {
                // gameRunning = 0;
                healthCount--;
                if (healthCount == 0)
                {
                    livesCount--;
                    gameRunning = 0;
                }
            }
            if (SMap[Bomb1X + 1][Bomb1Y] == '#')
            {
                Bomb1Flag = "OBSTRUCT";
                gotoxy(Bomb1Y, Bomb1X);
                cout << " ";
            }
        }
    }
}
void Alien2Bomb()
{
    // int bombs = AlienBomb();
    if (Bomb2Flag == "CLEAR")
    {
        if (SMap[Bomb2X + 1][Bomb2Y] == ' ' || SMap[Bomb2X + 1][Bomb2Y] == 'P')
        {
            SMap[Bomb2X][Bomb2Y] = ' ';
            gotoxy(Bomb2Y, Bomb2X);
            cout << " ";

            Bomb2X++;
            gotoxy(Bomb2Y, Bomb2X);
            cout << "*";
            gotoxy(Bomb2Y, Bomb2X - 1);
            cout << " ";
            if (Bomb2X == PlayerX && Bomb2Y == PlayerY)
            {
                // gameRunning = 0;
                healthCount--;
                if (healthCount == 0)
                {
                    livesCount--;
                    gameRunning = 0;
                }
            }
            if (SMap[Bomb2X + 1][Bomb2Y] == '#')
            {
                Bomb2Flag = "OBSTRUCT";
                gotoxy(Bomb2Y, Bomb2X);
                cout << " ";
            }
        }
    }
}

void Alien3Bomb()
{

    if (Bomb3Flag == "CLEAR")
    {
        if (SMap[Bomb3X + 1][Bomb3Y] == ' ' || SMap[Bomb3X + 1][Bomb3Y] == 'P')
        {
            SMap[Bomb3X][Bomb3Y] = ' ';
            gotoxy(Bomb3Y, Bomb3X);
            cout << " ";

            Bomb3X++;
            gotoxy(Bomb3Y, Bomb3X);
            cout << "*";
            gotoxy(Bomb3Y, Bomb3X - 1);
            cout << " ";
            if (Bomb3X == PlayerX && Bomb3Y == PlayerY)
            {
                // gameRunning = 0;
                healthCount--;
                if (healthCount == 0)
                {
                    livesCount--;
                    gameRunning = 0;
                }
            }
            if (SMap[Bomb3X + 1][Bomb3Y] == '#')
            {
                Bomb3Flag = "OBSTRUCT";
                gotoxy(Bomb3Y, Bomb3X);
                cout << " ";
            }
        }
    }
}

void Alien4Bomb()
{
    // int bombs = AlienBomb();
    if (Bomb4Flag == "CLEAR")
    {
        if (SMap[Bomb4X + 1][Bomb4Y] == ' ' || SMap[Bomb4X + 1][Bomb4Y] == 'P')
        {
            SMap[Bomb4X][Bomb4Y] = ' ';
            gotoxy(Bomb4Y, Bomb4X);
            cout << " ";

            Bomb4X++;
            gotoxy(Bomb4Y, Bomb4X);
            cout << "*";
            gotoxy(Bomb4Y, Bomb4X - 1);
            cout << " ";
            if (Bomb4X == PlayerX && Bomb4Y == PlayerY)
            {
                // gameRunning = 0;
                healthCount--;
                if (healthCount == 0)
                {
                    livesCount--;
                    gameRunning = 0;
                }
            }
            if (SMap[Bomb4X + 1][Bomb4Y] == '#')
            {
                Bomb4Flag = "OBSTRUCT";
                gotoxy(Bomb4Y, Bomb4X);
                cout << " ";
            }
        }
    }
}
void checkWalls()
{
    if (Bomb1Flag == "OBSTRUCT")
    {
        Bomb1Flag = "CLEAR";
        Bomb1X = Alien1X;
        Bomb1Y=Alien1Y;
    }
    if (Bomb2Flag == "OBSTRUCT")
    {
        Bomb2Flag = "CLEAR";
        Bomb2X = Alien2X;
        Bomb2Y = Alien2Y;
    }
    if (Bomb3Flag == "OBSTRUCT")
    {
        Bomb3Flag = "CLEAR";
        Bomb3X = Alien3X;
        Bomb3Y=Alien3Y;
    }
    if (Bomb4Flag == "OBSTRUCT")
    {
        Bomb4Flag = "CLEAR";
        Bomb4X = Alien4X;
        Bomb4Y = Alien4Y;
    }
    if (BulletFlag == "OBSTRUCT")
    {
        BulletFlag = "CLEAR";
        PlayerFireX = PlayerX;
        PlayerFireY = PlayerY;
        BulletFire = 0;
    }
    if (DebrisD == "UP")
    {
        DebrisD = "DOWN";
        DebrisX = 1 + rand() % 23;
        DebrisY = 1 + rand() % 69;
    }
}
void fireSpace()
{
    if (BulletFlag == "CLEAR")
    {
        if (SMap[PlayerFireX - 1][PlayerFireY] == ' ')
        {
            SMap[PlayerFireX][PlayerFireY] = ' ';
            gotoxy(PlayerFireY, PlayerFireX);
            cout << " ";

            PlayerFireX--;
            gotoxy(PlayerFireY, PlayerFireX);
            cout << "|";
            gotoxy(PlayerFireY, PlayerFireX + 1);
            cout << " ";
            if (SMap[PlayerFireX - 1][PlayerFireY] == '#')
            {
                BulletFlag = "OBSTRUCT";
                gotoxy(PlayerFireY, PlayerFireX);
                cout << " ";
            }
        }
    }
}
void moveBullet()
{
    fireSpace();
}
void instructions()
{
    system("cls");
    gotoxy(12, 10);
    cout << "************************************" << endl;
    gotoxy(12, 11);
    cout << "****       SPACE INVADERS       ****" << endl;
    gotoxy(12, 12);
    cout << "************************************" << endl;
    gotoxy(12, 13);
    cout << "1. Use ARROW KEYS for moving Player. You are permitted to move the player horizontally." << endl;
    gotoxy(12, 14);
    cout << "2. Use Space Bar to fire the Player's Bullets." << endl;
    gotoxy(12, 15);
    cout << "3. Avoid the Alien's Bombs. and Debris coming towards you." << endl;
    gotoxy(12, 16);
    cout << "        *******     GOOD LUCK!   ******" << endl;
}
char initializermenu()
{
    gotoxy(20, 10);
    cout << "************************************" << endl;
    gotoxy(20, 11);
    cout << "****       SPACE INVADERS       ****" << endl;
    gotoxy(20, 12);
    cout << "************************************" << endl;
    gotoxy(20, 13);
    cout << "1. Play The Game." << endl;
    gotoxy(20, 14);
    cout << "2. Instructions." << endl;
    gotoxy(20, 15);
    cout << "3. Exit." << endl;
    gotoxy(20, 16);
    cout << "Enter your Option: " << endl;
    char option;
    cin >> option;
    system("cls");
    return option;
}
void storeData()
{
    fstream file;
    file.open("MazeRunner.txt", ios::out);
    for (int x = 0; x < 27; x++)
    {
        for (int c = 0; c < 75; c++)
        {
            file << SMap[x][c];
        }
        file << endl;
    }
    file.close();
}
void ScoreIncrease()
{
    if ((PlayerFireX == Alien1X && PlayerFireY == Alien1Y) || (PlayerFireX == Alien1X && PlayerFireY == Alien1Y + 1) || (PlayerFireX == Alien1X && PlayerFireY == Alien1Y - 1) || (PlayerFireX == Alien2X && PlayerFireY == Alien2Y) ||
        (PlayerFireX == Alien2X && PlayerFireY == Alien2Y + 1) || (PlayerFireX == Alien2X && PlayerFireY == Alien2Y - 1) ||
        (PlayerFireX == Alien3X && PlayerFireY == Alien3Y) || (PlayerFireX == Alien3X && PlayerFireY == Alien3Y + 1) ||
        (PlayerFireX == Alien3X && PlayerFireY == Alien3Y - 1) || (PlayerFireX == Alien4Y && PlayerFireY == Alien4Y) ||
        (PlayerFireX == Alien4Y && PlayerFireY == Alien4Y + 1) || (PlayerFireX == Alien4Y && PlayerFireY == Alien4Y - 1))
    {
        score = score + 10;
    }
}
void Debris()
{
    if (DebrisD == "DOWN")
    {
        if (SMap[DebrisX + 1][DebrisY] == ' ')
        {
            SMap[DebrisX][DebrisY] = ' ';
            gotoxy(DebrisY, DebrisX);
            cout << " ";

            DebrisX++;
            gotoxy(DebrisY, DebrisX);
            cout << "+";
            gotoxy(DebrisY, DebrisX - 1);
            cout << " ";
            if (PlayerX == DebrisX && PlayerY == DebrisY)
            {
                healthCount--;
                if (healthCount == 0)
                {
                    livesCount--;
                    gameRunning = 0;
                }
            }
        }
        if (SMap[DebrisX + 1][DebrisY] == '#')
        {
            DebrisD = "UP";
            gotoxy(DebrisY, DebrisX);
            cout << " ";
        }
    }
}
void loadData()
{
    fstream file;
    string item;
    int rows = 0;
    file.open("MazeRunner.txt", ios::in);
    while (!file.eof())
    {
        
            getline(file, item);
            if (item == " " || item == "\0")
                break;

            for (int i = 0; i < 74; i++)
            {
                SMap[rows][i] = item[i];
            }
        
            rows++;
        
    }
}

bool isWinner()
{
    if (score >= 250)
    {
        return 1;
    }
    return 0;
}
void decreaseAlien()
{
    if ((PlayerFireX == Alien1X && PlayerFireY == Alien1Y) || (PlayerFireX == Alien1X && PlayerFireY == Alien1Y + 1) || (PlayerFireX == Alien1X && PlayerFireY == Alien1Y - 1))
        Alien1H--;
    if ((PlayerFireX == Alien2X && PlayerFireY == Alien2Y) ||
        (PlayerFireX == Alien2X && PlayerFireY == Alien2Y + 1) || (PlayerFireX == Alien2X && PlayerFireY == Alien2Y - 1))
        Alien2H--;
    if ((PlayerFireX == Alien3X && PlayerFireY == Alien3Y) || (PlayerFireX == Alien3X && PlayerFireY == Alien3Y + 1) ||
        (PlayerFireX == Alien3X && PlayerFireY == Alien3Y - 1))
        Alien3H--;
    if ((PlayerFireX == Alien4Y && PlayerFireY == Alien4Y) ||
        (PlayerFireX == Alien4Y && PlayerFireY == Alien4Y + 1) || (PlayerFireX == Alien4Y && PlayerFireY == Alien4Y - 1))
        Alien4H--;
    AlienLive++;
}
void pause()
{
    char n;
    gotoxy(90,14);
    cout<<"Enter 1 to pause. "<<endl;
    gotoxy(90,15);
    cout<<"Enter any key to resume";
    gotoxy(90,16);
    cin>>n;
    while (n == '1')
    {

    }
}
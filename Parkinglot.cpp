#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int parkinglot[3][5]; // parking lot structure
void putPos()         // taking input from user
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "Enter digits(0/1/2) in [" << i << "] floor corresponding to[" << j + 1 << "] position: ";
            cin >> parkinglot[i][j];
        }
    }
}
void PrintSpace() // printing parking lot on console
{
    system("CLS");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << parkinglot[i][j] << "\t";
        }
        cout << "\n";
    }
}

void FindPath(int i); // to print path of cars
int main()            // main function
{
    putPos();
    PrintSpace();
    for (int i = 0; i < 3; i++)
    {
        FindPath(i);
    }
} // end main
void FindPath(int i)
{
    int countLeft = 0, countRight = 0;
    bool flagRight = 0, flagLeft = 0;
    int tempval = -1;
    int index = 0, indexT = 0;
    for (int j = 0; j < 5; j++)
    {
        if (parkinglot[i][j] == 2)
        {
            index = j;//4
            break;
        }
    }

    ;
    if (i == 0 || i == 1)
    {
        for (int k = index; k < 5; k++) // checking the right moving loop
        {
            if (parkinglot[i][k] == 1)
            {
                if (flagLeft == 0)
                {
                    flagRight = 1;
                    countRight = k;
                    indexT = k;
                    break;
                }
                
            }
        }
        for (int l = index; l >= 0; l--) // checking left moving loop
        {
            if (parkinglot[i][l] == 1)
            {
                if (flagRight == 0)
                {
                    flagLeft = 1;
                    countLeft = l;
                    indexT = l;
                    break;
                }
            }
            
        }
    }
    else if (i == 2)
    {
        for (int k = index; k < 5; k++) // checking the right moving loop
        {
            countRight = k;
            if (k == 4)
                flagRight = 1;
        }
        countRight = countRight - index;
    }

    if (flagLeft)
    {
        cout << "Step Left : " << countLeft +1 << endl;
        if (i < 2)
            cout << "Down Step: 1" << endl;
    }
    if (flagRight)
    {
        cout << "Step Right  : " << countRight << endl;
        if (i < 2)
            cout << "Down Step: 1" << endl;
    }
    if (i < 2)
        parkinglot[i + 1][indexT] = 2;
    // PrintSpace();
}
#include <iostream>
using namespace std;
#include <conio.h>
void addition();
void subtraction();
void multiplication();
void scalarmulti(int, int);
bool isidentity(int);
void transpose(int);
bool isdiagonal(int);
bool isymetric(int);
void header();
int matrix1[10][10], matrix2[10][10], matrix3[10][10];
int row, col, option = 10, loop1, loop2, loop3, matrixnum, num, sum;
int trans[10][10], t[10][10];
bool flag = true;
char conti;
int main()
{
    char op = '9';
    cout << "enter the number of rows=";
    cin >> row;
    cout << "enter the number of column=";
    cin >> col;

    for (loop1 = 0; loop1 < row; loop1++)

    {
        for (loop2 = 0; loop2 < col; loop2++)
        {
            cout << "enter " << loop1 << "x" << loop2 << "=";
            cin >> matrix1[loop1][loop2];
        }
    }

    cout << endl;
    for (loop1 = 0; loop1 < row; loop1++)

    {
        for (loop2 = 0; loop2 < col; loop2++)
        {
            cout << "enter " << loop1 << "x" << loop2 << "=";
            cin >> matrix2[loop1][loop2];
        }
    }
    system("cls");
    do
    {
        system("cls");
        header();
        cout << "1 addition" << endl;
        cout << "2 subtraction" << endl;
        cout << "3 multiplication" << endl;
        cout << "4 scalarmulti" << endl;
        cout << "5 isidentity" << endl;
        cout << "6 transpose" << endl;
        cout << "7 isdiagonal" << endl;
        cout << "8 isymetric" << endl;
        cout << "9 Exit" << endl;
        cout << "Enter your option=";
        cin >> op;

        if (op == '1')
        {
            addition();
            cout << "press any key to conitnue=";
            cin >> conti;
        }
        if (op == '2')
        {
            subtraction();
            cout << "press any key to conitnue=";
            cin >> conti;
        }
        if (op == '3')
        {
            multiplication();
            cout << "press any key to conitnue=";
            cin >> conti;
        }
        if (op == '4')
        {
            cout << "Enter the number by which you want to multiply the matrix=";
            cin >> num;
            cout << "Enter the number of matrix by which you want to multiply (1 or 2)=";
            cin >> matrixnum;
            scalarmulti(matrixnum, num);
            cout << "press any key to conitnue=";
            cin >> conti;
        }
        if (op == '5')
        {
            cout << "Enter the number of matrix  by which you want to multiply (1 or 2)=";
            cin >> matrixnum;

            flag = isidentity(matrixnum);
            if (flag == true)
            {
                cout << "The matrix is an identity matrix \n";
                cout << "press any key to conitnue=";
                cin >> conti;
            }
            if (flag == false)
            {
                cout << "The matrix is not an identity matrix\n";
                cout << "press any key to conitnue=";
                cin >> conti;
            }
        }
        if (op == '6')
        {
            cout << "Enter the number of matrix which you want to transpose (1 or 2)=";
            cin >> matrixnum;
            transpose(matrixnum);
            cout << "press any key to conitnue=";
            cin >> conti;
        }
        if (op == '7')
        {
            cout << "Enter the number of matrix which you want to check diagnolity (1 or 2)=";
            cin >> matrixnum;
            flag = isdiagonal(matrixnum);
            if (flag == true)
            {
                cout << "The matrix is a diagonal matrix\n ";
                cout << "press any key to conitnue=";
                cin >> conti;
            }
            if (flag == false)
            {
                cout << "The matrix is not a diagonal matrix\n";
                cout << "press any key to conitnue=";
                cin >> conti;
            }
        }
        if (op == '8')
        {
            cout << "Enter the number of matrix which you want to check symmetricity (1 or 2)=";
            cin >> matrixnum;
            flag = isymetric(matrixnum);
            if (flag == true)
            {
                cout << "The matrix is a symetric matrix \n";
                cout << "press any key to conitnue=";
                cin >> conti;
            }
            if (flag == false)
            {
                cout << "The matrix is not a symetric matrix \n";
                cout << "press any key to conitnue=";
                cin >> conti;
            }
        }
        // if (op == 9)
        // {
        //     break;
        // }
        // if (!(op >= 1 & op <= 9))
        // {
        //     cout << "Enter your option again=";
        //     cin >> op ;
        // }

    } while (op != '9');
}

void addition()
{
    for (loop1 = 0; loop1 < row; loop1++)

    {
        for (loop2 = 0; loop2 < col; loop2++)
        {
            matrix3[loop1][loop2] = matrix1[loop1][loop2] + matrix2[loop1][loop2];
        }
    }

    cout << "So, the sum of the two matrixs is =" << endl;
    for (loop1 = 0; loop1 < row; loop1++)

    {
        for (loop2 = 0; loop2 < col; loop2++)
        {
            cout << matrix3[loop1][loop2] << " ";
        }
        cout << endl;
    }
}

void subtraction()
{
    for (loop1 = 0; loop1 < row; loop1++)

    {
        for (loop2 = 0; loop2 < col; loop2++)
        {
            matrix3[loop1][loop2] = matrix1[loop1][loop2] - matrix2[loop1][loop2];
        }
    }

    cout << "So, the difference of the two matrixs is =" << endl;
    for (loop1 = 0; loop1 < row; loop1++)

    {
        for (loop2 = 0; loop2 < col; loop2++)
        {
            cout << matrix3[loop1][loop2] << " ";
        }
        cout << endl;
    }
}

void transpose(int matrixnum)
{
    if (matrixnum == 1)
    {
        for (loop1 = 0; loop1 < row; loop1++)
        {
            for (loop2 = 0; loop2 < col; loop2++)
            {
                trans[loop2][loop1] = matrix1[loop1][loop2];
            }
        }
        cout << "So, the transpose of the matrix is =" << endl;
        for (loop1 = 0; loop1 < col; loop1++)
        {
            for (loop2 = 0; loop2 < row; loop2++)
            {
                cout << trans[loop1][loop2] << " ";
            }
            cout << endl;
        }
    }

    if (matrixnum == 2)
    {
        for (loop1 = 0; loop1 < row; loop1++)
        {
            for (loop2 = 0; loop2 < col; loop2++)
            {
                trans[loop2][loop1] = matrix2[loop1][loop2];
            }
        }
        cout << "So, the transpose of the matrix is =" << endl;
        for (loop1 = 0; loop1 < col; loop1++)
        {
            for (loop2 = 0; loop2 < row; loop2++)
            {
                cout << trans[loop1][loop2] << " ";
            }
            cout << endl;
        }
    }
}

void multiplication()
{
    for (loop1 = 0; loop1 < row; loop1++)
    {
        for (loop2 = 0; loop2 < col; loop2++)
        {
            sum = 0;
            for (loop3 = 0; loop3 <= col; loop3++)
            {
                sum = sum + matrix1[loop1][loop3] * matrix2[loop3][loop2];
                matrix3[loop1][loop2] = sum;
            }
        }
    }

    cout << "So, the multiplication of two matrixs is =" << endl;
    for (loop1 = 0; loop1 < row; loop1++)
    {
        for (loop2 = 0; loop2 < col; loop2++)
        {
            cout << matrix3[loop1][loop2] << " ";
        }
        cout << endl;
    }
}

void scalarmulti(int matrixnum, int num)
{
    if (matrixnum == 1)
    {
        for (loop1 = 0; loop1 < row; loop1++)
        {
            for (loop2 = 0; loop2 < col; loop2++)
            {
                matrix1[loop1][loop2] = (num * matrix1[loop1][loop2]);
            }
        }
        cout << "So, the multiplication of matrix by scalar number is  =" << endl;
        for (loop1 = 0; loop1 < row; loop1++)
        {
            for (loop2 = 0; loop2 < col; loop2++)
            {
                cout << matrix1[loop1][loop2] << " ";
            }
            cout << endl;
        }
    }

    if (matrixnum == 2)
    {
        for (loop1 = 0; loop1 < row; loop1++)
        {
            for (loop2 = 0; loop2 < col; loop2++)
            {
                matrix2[loop1][loop2] = (num * matrix2[loop1][loop2]);
            }
        }
        cout << "So, the multiplication of matrix by scalar number is  =" << endl;
        for (loop1 = 0; loop1 < row; loop1++)
        {
            for (loop2 = 0; loop2 < col; loop2++)
            {
                cout << matrix2[loop1][loop2] << " ";
            }
            cout << endl;
        }
    }
}
bool isidentity(int matrixnum)
{

    if (matrixnum == 1)
    {
        for (loop1 = 0; loop1 < row; loop1++)
        {
            for (loop2 = 0; loop2 < col; loop2++)
            {
                if (matrix1[loop1][loop2] != 1 && matrix1[loop1][loop2] != 0)
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
            }
        }
        return (flag);
    }

    if (matrixnum == 2)
    {
        for (loop1 = 0; loop1 < row; loop1++)
        {
            for (loop2 = 0; loop2 < col; loop2++)
            {
                if (matrix2[loop1][loop2] != 1 && matrix2[loop1][loop2] != 0)
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
            }
        }
        return (flag);
    }

    return flag;
}

bool isdiagonal(int matrixnum)
{
    if (matrixnum == 1)
    {
        for (loop1 = 0; loop1 < row; loop1++)
        {
            for (loop2 = 0; loop2 < col; loop2++)
            {
                if (loop1 != loop2 && matrix1[loop1][loop2] != 0)
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
            }
        }
        return (flag);
    }

    if (matrixnum == 2)
    {
        for (loop1 = 0; loop1 < row; loop1++)
        {
            for (loop2 = 0; loop2 < col; loop2++)
            {
                if (loop1 != loop2 && matrix2[loop1][loop2] != 0)
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
            }
        }
        return (flag);
    }

    return (flag);
}
bool isymetric(int matrixnum)
{
    if (matrixnum == 1)
    {
        transpose(1);
        for (loop1 = 0; loop1 < row; loop1++)
        {
            for (loop2 = 0; loop2 < col; loop2++)
            {
                if (matrix1[loop1][loop2] != trans[loop1][loop2])
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
            }
        }
        return (flag);
    }

    if (matrixnum == 2)
    {
        transpose(2);
        for (loop1 = 0; loop1 < row; loop1++)
        {
            for (loop2 = 0; loop2 < col; loop2++)
            {
                if (matrix2[loop1][loop2] != trans[loop1][loop2])
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
            }
        }
        return (flag);
    }
    return (flag);
}
void header()
{
    cout<<"-------------------"<<endl;
    cout<<"Matrices Calculator"<<endl;
    cout<<"-------------------"<<endl;
}
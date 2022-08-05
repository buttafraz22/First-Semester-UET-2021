#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
// data structures
struct Marks // marks structure
{
    string subject;
    float data;
    Marks *Next;
};

struct Student // student structure,only takes name
{              // points to marks in the rest
    string name;
    Student *Next;
    Marks *mNext; // pointer to marks structure
};
Student *head = NULL; // Various pointer type variables
Marks *headP = NULL;
Marks *Place = NULL;
int row1 = 0, row = 0, col = 10; // for screen output
// function prototypes
Student *getLastRecord();
void takein();
void addrecord(string, string, float);
bool search(string, string, float);
void clearScreen();
void consoleout(int, char);
Marks *getLastMarks(Marks *temp);
void app(Student *temp, string, float);
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
int main()
{
    system("cls");
    bool process = 1;
    while(process)
    {
        takein();
        clearScreen();
        char ask;
        gotoxy(1,29);
        cin>>ask;
        if(ask == '1')
            process = 0;
    }
    return 0;
}
void app(Student *temp, string sub, float marks)
{
    headP = temp->mNext;
    Marks *Record = new Marks;
    Record->subject = sub;
    Record->data = marks;
    Record->Next = NULL;
    Marks *findLast = getLastMarks(headP);
    findLast->Next = Record;
    Place = Record;
    consoleout(col,'X');
}
bool search(string name, string subject, float marks)
{
    Student *temp = head;
    row1=0;

    while(temp!=NULL)
    {
        if(temp->name==name)
        {
            app(temp,subject,marks);
            return true;
        }
        temp=temp->Next;
        row1++;
    }

    return false;
}
void takein()
{
    string name, sub;
    float score;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter subject: ";
    cin >> sub;
    cout << "Ente Marks Obtained: ";
    cin >> score;
    addrecord(name, sub, score);
}
void addrecord(string name, string sub, float score)
{
    bool isFound = search(name, sub, score);
    if (!isFound)
    {
        Student *Data = new Student;
        Marks *Data1 = new Marks;
        Data->name = name;
        Data1->subject = sub;
        Data1->data = score;
        Data->Next = NULL;
        Data->mNext = NULL;
        Data1->Next = NULL;
        if (head == NULL)
        {
            head = Data;
            headP = Data1;
            head->mNext = headP;
        }
        else
        {
            row++;
            headP = Data1;
            Data->mNext = headP;
            Student *temp = getLastRecord();
            temp->Next = Data;
        }
        consoleout(0, 'Y');
    }
}
void consoleout(int a1, char x1)
{
    if (x1 == 'Y')
    {
        Student *temp = getLastRecord();

        gotoxy(1, row * 5);
        cout << temp->name;

        Marks *temp1 = temp->mNext;
        gotoxy(10, row * 5);
        cout << "-> " << temp1->subject;
        gotoxy(13, row * 5 + 1);
        cout << temp1->data;
    }
    else
    {
        gotoxy(a1, row1 * 5);
        cout << "-> " << Place->subject;
        gotoxy(a1 + 3, row1 * 5 + 1);
        cout << Place->data;
    }
}
Student *getLastRecord()
{
    Student *temp = head;

    while(temp->Next!=NULL)
    {
        temp=temp->Next;
    }

    return temp;
}
Marks *getLastMarks(Marks *temp)
{
    col=10;
    while(temp->Next!=NULL)
    {
        temp=temp->Next;
        col+=10;
    }
    col+=10;

    return temp;
}
void clearScreen()
{
    gotoxy(0,30);
    cout << "                                       ";
    cout << "\n                                     ";
    cout << "\n                                     ";
}
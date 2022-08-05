#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
char menu();
void header();
void clearScreen();
struct football
{
    string name;
    int position;
    int touchdowns;
    int catches;
    int passingYard;
    int recYards;
    int rushYards;
};
string data;
void store(football players[]);
void readData(football players[]);
string parseData(string data,int column);
void loadData(football players[],string data);
void takeInput(football players[]);
void PrintInfo(football players[]);
int count = 0;
main()
{
    football players[10];
    readData(players);
    // loadData(players,data);
    char opt;
    bool flag = 1;
    do
    {
        system("cls");
        opt = menu();
        if(opt == '1')
        {
            takeInput(players);
            clearScreen();
        }
        if(opt == '2')
        {
            PrintInfo(players);
            clearScreen();
        }
        if(opt == '3')
        {
            store(players);
        }
        if(opt == '4')
        {
            flag = false;
        }
    }while(flag);
    

}
char menu()
{
    char option;
    cout << "1.Add All Players...\n";
    cout << "2.View All Players...\n";
    cout << "3.Store players data in file...\n";
    cout << "4.Exit...\n";
    cout << "Enter your choice...\n";
    cin >> option;
    return option;
}
void takeInput(football players[])
{
    cout << "Enter Player Name: "<<endl;
    cin.ignore();
    getline(cin, players[count].name);
    cout << "Enter Player Position:  "<<endl;
    cin >> players[count].position;
    cout << "Enter Player Touchdowns:  "<<endl;
    cin >> players[count].touchdowns;
    cout << "Enter Player Catches:  "<<endl;
    cin >> players[count].catches;
    cout << "Enter Player Passing Yards:  "<<endl;
    cin >> players[count].passingYard;
    cout << "Enter Player Recieving Yards:  "<<endl;
    cin >> players[count].recYards;
    cout << "Enter Player Rushing Yards:  "<<endl;
    cin >> players[count].rushYards;
    count++;
    //return players;
}

void PrintInfo(football players[])
{
    for(int i = 0; i < count; i++)
    {
        cout << players[i].name << "\t";
        cout << players[i].position << "\t";
        cout << players[i].touchdowns << "\t";
        cout << players[i].catches << "\t";
        cout << players[i].passingYard << "\t";
        cout << players[i].recYards << "\t";
        cout << players[i].rushYards;
        cout << "\n";
    }
    cout << endl;
}
void clearScreen()
{ //____clear screen_____
    cout << "Press any key to continue " << endl;
    getch();
    system("CLS");
}

void store(football players[])
{
    fstream file;
        file.open("Football.txt", ios :: app);
        for(int i = 0; i < count; i++)
        {
            file << players[i].name << "," << players[i].position << "," << players[i].touchdowns  << "," << players[i].catches << "," << players[i].passingYard << "," << players[i].recYards << "," << players[i].rushYards<<endl;
            cout << endl;
        }
    file.close();
}

void readData(football players[])
{
    fstream file;
    file.open("Football.txt", ios :: in);
        getline(file,data);
        file >> data;
    file.close();
}

string parseData(string data,int column)
{
    string item;
    int comma = 1;
    fstream file;
    for(int i = 0; i < data.length(); i++)
    {
        if(data[i] == ',')
        {
            comma++;
        }
        else if(comma == column)
        {
            item = item + data[i];
        }
    }
    return item;
}

void loadData(football players[],string data)
{
    fstream file;
    int i = 0;
    file.open("Football.txt", ios :: in);
        while(!file.eof())
        {
            getline(file,data);
            players[i].name = parseData(data,1);
            players[i].position = atoi(parseData(data,2).c_str());
            players[i].touchdowns = atoi(parseData(data,3).c_str());
            players[i].catches = atoi(parseData(data,4).c_str());
            players[i].passingYard = atoi(parseData(data,5).c_str());
            players[i].recYards = atoi(parseData(data,6).c_str());
            players[i].rushYards = atoi(parseData(data,7).c_str());
            i++;
        }
    file.close();
}
void header()
{
    cout<<"-------------------";
    cout<<"Football Management";
    cout<<"-------------------";
}
#include<iostream>
using namespace std;
void display();
void TimeTick(int x);
char problemObj[5][5] ={{'-', '#', '#','-', 'T'},
                      {'/','-','-', '/','-'},
                      {'-', '#','-','-','-'},
                      {'/','-', '#','-', '#'},
                      {'T','-','-','-','-'}};
int main()
{
    cout<<"T is the target object"<<"\n";
    display();
    TimeTick(4);
    cout<<"\n";
    cout<<"\n";
    display();
    return 0;
}
void display()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5 ; j++)
        {
            cout<<problemObj[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void TimeTick(int para)
{
    char placeHolder;
    for(int i = 0 ; i < para ; i++)
    {
        for(int j = 0; j < 5 ; j++)
        {
            placeHolder = problemObj[4][j];
            for(int k = 4 ; k >= 0 ; k--)
            {
                problemObj[k+1][j] = problemObj[k][j];
            }
            problemObj[0][j] = placeHolder;
        }
    }
}
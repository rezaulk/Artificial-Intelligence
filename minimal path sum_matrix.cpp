#include<iostream>

using namespace std;

int matrix[5][5];
int cost;

void Amatrix()
{
    int a=0,b=0;
    cost=matrix[0][0];
    int i=0,j=0;
    while(i!=5&&j!=5)
    {
        int x=matrix[i][j+1];
        int y=matrix[i+1][j];
        x=x+cost;
        y=y+cost;
        matrix[i+1][j]=y;
        matrix[i][j+1]=x;
        if(y<x)
        {
            cost=y;
            i++;
        }
        else
        {
            cost=x;
            j++;
        }
    }
}

int main()
{
    cout<<"Enter cost 5 X 5:";
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            int x;
            cin>>x;
            matrix[i][j]=x;
        }
    }
    Amatrix();
    cout<<endl;
    cout<<cost<<endl;
    /*for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }*/
}
/*131 673 234 103 18
201 96 342 965 150
630 803 746 422 111
537 699 497 121 956
805 732 524 37 331*/

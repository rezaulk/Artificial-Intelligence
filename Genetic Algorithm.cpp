#include<bits/stdc++.h>
using namespace std;

string population[4]= {"01100","10110","01101","00111"};
string crosspopulation[4];
int arr[4];
int countIteration=0;

///Binary To Decimal Convert ///

int BinaryTODecimal(int x)
{
    int i=0,remainder,decimal=0;
    while(x!=0)
    {
        remainder=x%10;
        x=x/10;
        decimal=decimal+remainder*pow(2,i);
        i++;
    }
    return decimal;
}

///Decimal To Binary Convert ///

int DecimalTOBinary(int x)
{
    int i=1,remainder,binary=0;
    while(x!=0)
    {
        remainder=x%2;
        x=x/2;
        binary=binary+remainder*i;
        i=i*10;
    }
    cout<<binary<<endl;
}

///CrossOver Between Two String ///

int crossover(int a,int b)
{
    string x,y;
    x=population[a];
    y=population[b];
    srand (time(NULL));
    int p=rand()%4;
    srand(1);

    while(true)
    {
        if(p!=0)
        {
            //cout<<p<<endl;
            break;
        }
        else
        {
            p=rand()%4;
        }
    }
    int Dx=x.size();
    Dx=Dx-p;
    int Dy=y.size();
    Dy=Dy-p;

    string sx=x.substr(0,p);
    string sax=x.substr(p,Dx);
    string sy=y.substr(0,p);
    string say=y.substr(p,Dy);

    crosspopulation[a]=sx+say;
    crosspopulation[b]=sy+sax;

    srand (time(NULL));
    int mutation=rand()%9;
    srand(1);
    //cout<<mutation<<endl;
    int number=rand()%2;
    string crossA=crosspopulation[a];
    string crossB=crosspopulation[b];

    char c='0'+number;
    crossA[mutation]=c;
    crossB[mutation]=c;
    //crosspopulation[mutation]=s;

    //cout<<crossA<<endl;

    cout<<"before Cross : "<<population[a]<<" : "<<population[b]<<" Decimal : "<<arr[a]<<" : "<<arr[b]<<" Random Number : "<<p<<endl;

    population[a]=crossA;
    population[b]=crossB;

    int bm = atoi(population[a].c_str());
    arr[a]=BinaryTODecimal(bm);
    int bn = atoi(population[b].c_str());
    arr[b]=BinaryTODecimal(bn);

    cout<<"After  Cross : "<<population[a]<<" : "<<population[b]<<" Decimal : "<<arr[a]<<" : "<<arr[b]<<endl;
    //cout<<"a"<<sx<<endl;
    //cout<<"b"<<sax<<endl;
    //cout<<"c"<<sy<<endl;
    //cout<<"d"<<say<<endl;
    cout<<endl;
}

/// Check Decimal if Found 31///
bool checkIn()
{
    for(int i=0; i<4; i++)
    {
        if(arr[i]==31)
        {
            return true;
        }
    }
    //cout<<endl;
    return false;
}

///Main Genetic Algorithom///

void GenerateRandomNumber()
{
    if(checkIn()!=true)
    {
        countIteration++;
        bool check[4]= {false,false,false,false};
        srand (time(NULL));
        int ac=rand()%4;
        //srand(1);
        check[ac]=true;
        int b=rand()%4;
        check[b]=true;
        while(ac==b)
        {
            b=rand()%4;
            check[b]=true;
        }
        crossover(ac,b);
        //cout<<ac<<b<<endl;
        //cout<<population[ac]<<endl;
        //<<population[b]<<endl;
        int pk[2],y=0;
        for(int k=0; k<4; k++)
        {
            if(check[k]!=true)
            {
                pk[y]=k;
                y++;
            }
        }
        crossover(pk[0],pk[1]);
        //cout<<"ok"<<endl;
        //cout<<pk[1]<<pk[0]<<endl;
        //cout<<population[pk[0]]<<endl;
        //cout<<population[pk[1]]<<endl;
        GenerateRandomNumber();
    }
    else
    {
        cout<<"Find In "<<countIteration<<" number Iteration"<<endl;
    }
}

int main()
{
    for(int i=0; i<4; i++)
    {
        int b = atoi(population[i].c_str());
        arr[i]=BinaryTODecimal(b);
    }
    GenerateRandomNumber();
    return 0;
}

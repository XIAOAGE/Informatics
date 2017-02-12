#include <iostream>

using namespace std;

int n;
int arr[100][100];
int arr2[100];
string line1, line2, line3;



int low_to_number(char a)
{
    return a-96;
}

int up_to_number(char a)
{
    return a-38;
}

int handy(char a)
{
    return a<91 ? up_to_number(a) : low_to_number(a);
}

bool pre_solve()
{
    for(int i=0; i<line1.length(); i++)
    {
        arr2[handy(line1[i])]++;
    }
    
    for(int i=0; i<line2.length(); i++)
    {
        arr2[handy(line2[i])]++;
    }
    
    for(int i=0; i<line3.length(); i++)
    {
        arr2[handy(line3[i])]--;
    }
    
    for(int i=1; i<=52; i++)
    {
        if(arr2[i]) return false;
    }
    
    return true;
}

bool solve()
{
    int index1, index2;
    for(int i=1; i<line1.length(); i++)
    {
        index1 = handy(line1[i]);
        for(int j=i-1; j>=0; j--)
        {
            if(line1[i]==line1[j]) break;
            index2 = handy(line1[j]);
            arr[index1][index2]++;
        }
    }
    
    for(int i=1; i<line2.length(); i++)
    {
        index1 = handy(line2[i]);
        for(int j=i-1; j>=0; j--)
        {
            if(line2[i]==line2[j]) break;
            index2 = handy(line2[j]);
            arr[index1][index2]++;
        }
    }
    
    for(int i=1; i<line3.length(); i++)
    {
        index1 = handy(line3[i]);
        for(int j=i-1; j>=0; j--)
        {
            if(line3[i]==line3[j]) break;
            index2 = handy(line3[j]);
            arr[index1][index2]--;
        }
    }
    
    for(int i=1; i<=52; i++)
    {
        for(int j=1; j<=52; j++)
        {
            if(arr[i][j]>0) return false;
        }
    }
    
    return true;
}

void init()
{
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            arr[i][j] = 0;
        }
        arr2[i] = 0;
    }
}

int main()
{
    cin>>n;
    cin.ignore();
    for(int i=1; i<=n; i++)
    {
        init();
        cin>>line1>>line2>>line3;
        if(pre_solve() && solve())
        {
            cout<<"Data set "<<i<<": yes"<<endl;
        }
        else
        {
            cout<<"Data set "<<i<<": no"<<endl;
        }
    }
    return 0;
}

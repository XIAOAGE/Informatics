#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int val;
int arr[40];
bool dp[40][600][600];

double heron(double a, double b, double c)
{
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    cin>>N;
    int sum = 0;
    for(int i=0; i<N; i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    val = sum/3;
    
    dp[0][arr[0]][0] = true;
    dp[0][0][arr[0]] = true;
    
    for(int i=1; i<40; i++)
    {
        for(int j=0; j<600; j++)
        {
            for(int k=0; k<600; k++)
            {
                dp[i][j][k] = (j-arr[i]<0 ? false : dp[i-1][j-arr[i]][k]) || (k-arr[i]<0 ? false : dp[i-1][j][k-arr[i]]) || dp[i-1][j][k];
            }
        }
    }
    
    double ans = -1;
    for(int i=1; i<=sum/2; i++)
    {
        for(int j=1; j<=sum-i; j++)
        {
            if(i+j<=sum-i-j || sum-j<=j || sum-i<=i) continue;
            if(dp[N-1][i][j])
            {
                ans = max(ans, heron(i*1.0, j*1.0, sum*1.0-i*1.0-j*1.0));
            }
        }
    }
    if(ans == -1)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        int final = ans*100;
        cout<<final<<endl;
    }
    return 0;
}

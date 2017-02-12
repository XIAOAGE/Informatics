#include <iostream>
using namespace std;
#define max 105
int dp[max][max];
int a[max]; 
int min(int a,int b)
{
    return a>b?b:a;
}
int main()
{
    int n;
    cin>>n;
    int i,j,k;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n-2;i++)
        dp[i][i+2]=a[i]*a[i+1]*a[i+2];
    int len;
    for(len=3;len<n;len++)
        for(i=0;i+len<n;i++)
        {
            j=i+len;
            for(k=i+1;k<j;k++)
            {
                    if(dp[i][j]==0)
                        dp[i][j]=dp[i][k]+dp[k][j]+a[i]*a[k]*a[j];
                    else
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[j]*a[k]);
            }
        }
        cout<<dp[0][n-1]<<endl;
 
    return 0;
}

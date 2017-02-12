#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>

#define N 600

using namespace std;

int n,m,a[N],b[N],dp[N][N],pre[N][N],stk[N];

void go()
{
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int j=1;j<=m;j++) scanf("%d",&b[j]);
    memset(dp,0,sizeof dp);
    dp[0][0]=0;
    for(int i=1,ma,last;i<=n;i++)
    {
        ma=0;last=0;
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=ma+1;
                pre[i][j]=last;
            }
            else dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(b[j]<a[i]&&ma<dp[i-1][j])
            {
                ma=dp[i-1][j];
                last=j;
            }
        }
    }
    int ans=-1,x=n,y,p=0;
    for(int j=1;j<=n;j++)
        for(int i=1;i<=m;i++)
            if(ans<dp[j][i])
            {
                ans=dp[j][i];
                y=i;
            }
    printf("%d\n",ans);
    
    while(ans--)
    {
        stk[++p]=b[y];
        while(a[x]!=b[y]) x--;
        y=pre[x][y];
        x--;
    }
    for(int i=p;i>=1;i--) printf("%d ",stk[i]);
}

int main()
{
    while(scanf("%d",&n)!=EOF) go();
    return 0;
}

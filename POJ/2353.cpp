#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int M, N;
int map[100][500];
long long dp[100][500];
int path[100][500];

void solve();

int main()
{
    scanf("%d%d", &M, &N);
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    solve();
    return 0;
}
/*
#define max 100

string to_String(int n)
{
    int m=n;
    int i=0,j=0;
    char s[max];
    char ss[max];
    while(m>0)
    {
        s[i++]= m%10 + '0';
        m/=10;
    }
    s[i]='\0';
    
    i=i-1;
    while(i>=0)
    {
        ss[j++]=s[i--];
    }
    ss[j]='\0';
    
    return ss;
}
*/

void dfs(int x, int y)
{
    if(!path[x][y])
    {
        printf("%d\n", y+1);
        return;
    }
    if(path[x][y]==1)
    {
        dfs(x-1, y);
        printf("%d\n", y+1);
    }
    else if(path[x][y]==2)
    {
        dfs(x, y-1);
        printf("%d\n", y+1);
    }
    else if(path[x][y]==3)
    {
        dfs(x, y+1);
        printf("%d\n", y+1);
    }
}

void solve()
{
    for(int i=0; i<N; i++)
    {
        dp[0][i] = map[0][i];
    }
    
    for(int i=1; i<M; i++)
    {
        dp[i][0] = dp[i-1][0]+map[i][0];
        path[i][0] = 1;
        for(int j=1; j<N; j++)
        {
            if(dp[i-1][j]+map[i][j]<dp[i][j-1]+map[i][j])
            {
                dp[i][j] = dp[i-1][j]+map[i][j];
                path[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i][j-1]+map[i][j];
                path[i][j] = 2;
            }
        }
        for(int j=N-2; j>=0; j--)
        {
            if(dp[i][j+1]+map[i][j]<dp[i][j])
            {
                dp[i][j] = dp[i][j+1]+map[i][j];
                path[i][j] = 3;
            }
        }
    }
    
    long long ans = 2147483647;
    int y = -1;
    for(int i=0; i<N; i++)
    {
        if(ans>dp[M-1][i])
        {
            y = i;
            ans = dp[M-1][i];
        }
    }
    dfs(M-1, y);
}

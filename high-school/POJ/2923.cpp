#include <cstdio>
#include <iostream>

#define INF 0x3f3f3f3f

using namespace std;

int t, n, c1, c2;
int item[11];
int dp[2][101][1100];

void dfs(int d1, int d2, int state)
{
    if(dp[d1][d2][state]!=INF) return;
    if(state==0)
    {
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(!(state>>i&1)) continue;
        if(d1==0)
        {
            if(item[i]<=d2)
            {
                dfs(0,d2-item[i],state-(1<<i));
                dp[d1][d2][state] = min(dp[d1][d2][state], dp[0][d2-item[i]][state-(1<<i)]);
            }
            else
            {
                dfs(1, c2, state);
                dp[d1][d2][state] = min(dp[d1][d2][state], dp[1][c2][state]);
            }
        }
        else
        {
            if(item[i]<=d2)
            {
                dfs(1, d2-item[i],state-(1<<i));
                dp[d1][d2][state] = min(dp[d1][d2][state], dp[d1][d2-item[i]][state-(1<<i)]);
            }
            else
            {
                dfs(0, c1, state);
                dp[d1][d2][state] = min(dp[d1][d2][state], dp[0][c1][state]+1);
            }
        }
    }
}

int main()
{
    scanf("%d", &t);
    for(int dang=1; dang<=t; dang++)
    {
        scanf("%d%d%d", &n, &c1, &c2);
        for(int i=0; i<n; i++) scanf("%d", &item[i]);
        for(int i=0; i<2; i++)
            for(int j=0; j<=max(c1,c2); j++)
                for(int k=0; k<(1<<n); k++)
                    dp[i][j][k] = INF;
        for(int i=0; i<2; i++)
            for(int j=0; j<=max(c1, c2); j++)
                dp[i][j][0] = 1;
        dfs(0, c1, (1<<n)-1);
        printf("Scenario #%d:\n", dang);
        printf("%d\n", dp[0][c1][(1<<n)-1]);
        printf("\n");
    }
    return 0;
}

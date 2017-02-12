#include <bits/stdc++.h>

using namespace std;

int n, r;
int g[3][100010];
int dp[100010][5];

int main()
{
    scanf("%d%d", &n, &r);
    for(int i=1; i<=n; i++) scanf("%d", &g[1][i]);
    for(int i=1; i<=n; i++) scanf("%d", &g[2][i]);

    dp[1][0] = g[1][1]+g[2][1];
    dp[1][1] = r+g[2][1];
    dp[1][2] = r+g[1][1];
    dp[1][3] = r;
    dp[1][4] = 2*r;

    if(r>=0)
    {
        int ans = 0;
        for(int i=1; i<=2; i++)
            for(int j=1; j<=n; j++)
                ans += g[i][j]<r ? r : g[i][j];
        printf("%d\n", ans);
    }
    else
    {
        for(int i=2; i<=n; i++)
        {
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], max(dp[i-1][2], max(dp[i-1][3], dp[i-1][4]))))+g[1][i]+g[2][i];
            dp[i][1] = max(dp[i-1][0], max(dp[i-1][2], dp[i-1][3]))+r+g[2][i];
            dp[i][1] = max(dp[i][1], dp[i-1][1]+g[2][i]);
            dp[i][1] = max(dp[i][1], dp[i-1][4]+g[2][i]);
            dp[i][2] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][3]))+r+g[1][i];
            dp[i][2] = max(dp[i][2], dp[i-1][2]+g[1][i]);
            dp[i][2] = max(dp[i][2], dp[i-1][4]+g[1][i]);
            dp[i][3] = max(dp[i-1][0], max(dp[i-1][1], max(dp[i-1][2], dp[i-1][4])))+r;
            dp[i][3] = max(dp[i-1][3], dp[i][3]);
            dp[i][4] = dp[i-1][4];
            dp[i][4] = max(dp[i][4], dp[i-1][0]+2*r);
            dp[i][4] = max(dp[i][4], dp[i-1][1]+r);
            dp[i][4] = max(dp[i][4], dp[i-1][2]+r);
            dp[i][4] = max(dp[i][4], dp[i-1][3]+2*r);
        }
        printf("%d\n", max(dp[n][0], max(dp[n][1], max(dp[n][2], max(dp[n][3], dp[n][4])))));
    }
    return 0;
}

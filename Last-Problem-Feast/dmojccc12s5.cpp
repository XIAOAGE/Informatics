#include <bits/stdc++.h>

using namespace std;

int r, c, k;
int dp[30][30];

int main()
{
    cin>>r>>c>>k;
    int u, v;
    while(k--)
    {
        cin>>u>>v;
        dp[u][v] = -1;
    }
    dp[r][c] = 1;
    for(int i=r; i>=1; i--)
    {
        for(int j=c; j>=1; j--)
        {
            if(dp[i][j]==-1) continue;
            int t1 = i-1;
            int t2 = j-1;
            if(t1>=1 && dp[t1][j]!=-1) dp[t1][j] += dp[i][j];
            if(t2>=1 && dp[i][t2]!=-1) dp[i][t2] += dp[i][j];
        }
    }
    cout<<dp[1][1]<<endl;
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

#define INF -0x3f3f3f3f

using namespace std;

int n, m;
vector<int> vec[3010];
int g[3010][3010];
int p[3010];
int dp[3010][3010];

int dfs(int idx)
{
    int ret = 0;
    for(int i=0; i<vec[idx].size(); i++)
    {
        int nxt = vec[idx][i];
        ret += dfs(nxt);
    }
    if(ret==0)
    {
        ret=1;
        dp[idx][1] = p[idx];
        return ret;
    }
    for(int i=0; i<vec[idx].size(); i++)
    {
        int nxt = vec[idx][i];
        for(int j=ret; j>=0; j--)
        {
            for(int k=j; k>=0; k--)
            {
                dp[idx][j] = max(dp[idx][j], dp[idx][j-k]+dp[nxt][k]-g[idx][nxt]);
            }
        }
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    int a, b;
    for(int i=1; i<=n-m; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        for(int j=0; j<tmp; j++)
        {
            scanf("%d%d", &a, &b);
            g[i][a] = b;
            vec[i].push_back(a);
        }
    }
    for(int i=n-m+1; i<=n; i++)
    {
        scanf("%d", &p[i]);
    }
    for(int i=1; i<=n; i++)
    {
        dp[i][0] = 0;
        for(int j=1; j<=n; j++)
        {
            dp[i][j] = INF;
        }
    }
    int ans = -1;
    dfs(1);
    for(int i=n; i>=0; i--)
    {
        if(dp[1][i]>=0)
        {
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}

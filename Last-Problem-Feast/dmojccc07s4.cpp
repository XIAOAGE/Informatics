#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> g[10000];
int dp[10000];

int dfs(int ind)
{
    if(dp[ind]!=0) return dp[ind];
    if(ind==n)
    {
        dp[ind]=1;
        return 1;
    }
    int ret = 0;
    for(int i=0; i<g[ind].size(); i++)
    {
        ret += dfs(g[ind][i]);
    }
    dp[ind] = ret;
    return dp[ind];
}

int main()
{
    cin>>n;
    int a, b;
    while(cin>>a>>b && a!=0 && b!=0)
    {
        g[a].push_back(b);
    }
    dfs(1);
    cout<<dp[1]<<endl;
    return 0;
}

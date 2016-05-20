#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct city
{
    int number, length;
};

int n, k;
vector<city> vec[50001];
int dp[50001][2];
bool dest[50001];
bool mark[50001];

void input();

void dfs(int current, int pre)
{
    for(int i=0; i<vec[current].size(); i++)
    {
        int next = vec[current][i].number;
        if(next==pre) continue;
        int len = vec[current][i].length;
        dfs(next, current);
        if(mark[next])
        {
            dp[current][1] = min(dp[next][1]+dp[current][0]+len, dp[next][0]+2*len+dp[current][1]);
            dp[current][0] += dp[next][0] + 2*len;
            mark[current] = true;
        }
    }
    if(dest[current]) mark[current] = true;
}

void solve()
{
    dfs(k, -1);
    printf("%d\n", dp[k][1]);
}

int main()
{
    input();
    solve();
    return 0;
}

void input()
{
    scanf("%d %d", &n, &k);
    int a, b, d;
    for(int i=0; i<n-1; i++)
    {
        scanf("%d %d %d", &a, &b, &d);
        city tmp = {b, d};
        vec[a].push_back(tmp);
        city tmp2 = {a, d};
        vec[b].push_back(tmp2);
    }
    scanf("%d", &a);
    for(int i=0; i<a; i++)
    {
        scanf("%d", &b);
        dest[b] = true;
    }
}

/*
 看到有N点和N-1条边就能联想到树，使用树形dp：
 sum[0][u]：回到u点的最短路径
 
 sum[1][u]：不回到u点的最短路径
 
 sum[0][u]+=len*2+sum[0][v]//1
 sum[1][u]=min( len+sum[0][u]+sum[1][v],  sum[1][u]+sum[0][v]+len*2 )//2
 第一句很好理解，回到u就是回到v再加上u,v间路径的两倍（来回）
 min中1的意思是v之前u的孩子回到u再访问v且不回到u的值，2的意思是先从v出发返回u再访问之前其他的孩子且不回来的值，取最优。
 
 为什么？
 
 因为依题意可知最终只会停到一个点，同时我们要消除访问先后顺序对结果的影响，所以对于v来说可能停到v的子树或u其他孩子的子树中，这个取最优即可。
 */
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
    printf("%d\n", dp[k][1]); //因为起点不用算进去，所以回到起点的解不可能是最小值
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
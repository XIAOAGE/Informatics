#include <bits/stdc++.h>

using namespace std;

vector<int> g[1000000];
bool v1[1000000];
bool v2[1000000];
int n, m;
int a, b;

void dfs(int ind)
{
    if(v1[b]) return;
    for(int i=0; i<g[ind].size(); i++)
    {
        if(v1[g[ind][i]]) continue;
        v1[g[ind][i]] = true;
        dfs(g[ind][i]);
    }
}

void dfs2(int ind)
{
    if(v2[a]) return;
    for(int i=0; i<g[ind].size(); i++)
    {
        if(v2[g[ind][i]]) continue;
        v2[g[ind][i]] = true;
        dfs2(g[ind][i]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }
    scanf("%d%d", &a, &b);
    dfs(a);
    dfs2(b);
    if(v1[b]) cout<<"yes"<<endl;
    else if(v2[a]) cout<<"no"<<endl;
    else cout<<"unknown"<<endl;
    return 0;
}

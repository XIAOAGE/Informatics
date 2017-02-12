#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> g[110];
int in[110], ans[110];

void topo_sort()
{
    stack<int> sta;
    for(int i=1; i<=n; i++)
        if(in[i]==0)
            sta.push(i);

    int cnt = 0;
    while(!sta.empty())
    {
        if(sta.size()>1){} //means there's more than one topological solution
        int idx = sta.top(); sta.pop();
        ans[cnt++] = idx;
        for(int i=0; i<g[idx].size(); i++)
        {
            int nxt = g[idx][i];
            if(--in[nxt]==0) sta.push(nxt);
        }
    }
    if(cnt!=n){} //means there's no solution
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        int tmp;
        while(scanf("%d", &tmp) && tmp)
        {
            g[i].push_back(tmp);
            in[tmp]++;
        }
    }
    topo_sort();
    for(int i=0; i<n; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
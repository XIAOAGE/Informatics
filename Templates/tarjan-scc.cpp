#include <bits/stdc++.h>

using namespace std;

/*
comp[i] = j: the ith node belongs to component j.
sz[i]: the size of component i.
*/

int n, m, cnt, ti;
vector<int> g[5010];
int comp[5010], disc[5010], low[5010], sz[5010];
bool inSta[5010];
stack<int> sta;

void tarjan(int idx)
{
    disc[idx] = low[idx] = ++ti;
    sta.push(idx);
    inSta[idx] = true;

    for(int i=0; i<g[idx].size(); i++)
    {
        int nxt = g[idx][i];
        if(disc[nxt]==0)
        {
            tarjan(nxt);
            low[idx] = min(low[idx], low[nxt]);
        }
        else if(inSta[nxt]) low[idx] = min(low[idx], disc[nxt]);
    }

    if(low[idx]==disc[idx])
    {
        while(sta.top()!=idx)
        {
            int tmp = sta.top(); sta.pop();
            inSta[tmp] = false;
            comp[tmp] = cnt;
            sz[cnt]++;
        }
        int tmp = sta.top(); sta.pop();
        inSta[tmp] = false;
        comp[tmp] = cnt;
        sz[cnt]++;
        cnt++;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    ti = 0, cnt = 1;
    for(int i=0; i<m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }

    for(int i=1; i<=n; i++)
    {
        if(comp[i]) continue;
        tarjan(i);
    }
    return 0;
}

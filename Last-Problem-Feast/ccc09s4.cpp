#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> node;

int n, k, t, d;;
int p[5010];
vector<int> g[5010];
bool v[5010];
int dist[5010];
int dist2[5010];
int len[5010][5010];

int main()
{
    scanf("%d%d", &n, &t);
    int a, b, c;
    for(int i=0; i<t; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back(b);
        g[b].push_back(a);
        len[a][b] = len[b][a] = c;
    }
    scanf("%d", &k);
    memset(p, -1, sizeof p);
    for(int i=0; i<k; i++)
    {
        scanf("%d%d", &a, &b);
        p[a] = b;
    }
    scanf("%d", &d);
    priority_queue<node, vector<node>, greater<node>> pq;
    v[d] = true;
    dist[d] = 0;
    pq.push(node(0, d));
    memset(v, 0, sizeof v);
    for(int i=1; i<=n; i++) dist2[i] = INF;
    while(!pq.empty())
    {
        node cur = pq.top(); pq.pop();
        int ind  = cur.second;
        int dis = cur.first;
        if(v[ind]) continue;
        v[ind] = true;
        dist[ind] = dis;
        for(int i=0; i<g[ind].size(); i++)
        {
            if(v[g[ind][i]]) continue;
            if(dist2[g[ind][i]]<dis+len[ind][g[ind][i]]) continue;
            dist2[g[ind][i]] = dis+len[ind][g[ind][i]];
            pq.push(node(dis+len[ind][g[ind][i]], g[ind][i]));
        }
    }
    int ans = 0x3f3f3f3f;
    for(int i=1; i<=n; i++)
    {
        if(p[i]!=-1)
        {
            ans = min(ans, dist[i]+p[i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}

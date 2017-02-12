/*
FYI, there are bugs in this program
*/
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> node;

int m, cnt;
int a[2000][2000];
int c[2000][2000];
int d[2000][2000];
int b[10];
vector <int> g[110];
bool v[110];

int prim()
{
    memset(v, 0, sizeof v);
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push(node(0, 1));
    int ret = 0;
    while(!pq.empty())
    {
        node cur = pq.top(); pq.pop();
        int ind = cur.second;
        if(v[ind]) continue;
        v[ind] = true;
        int len = cur.first;
        ret += len;
        for(int i=0; i<g[ind].size(); i++)
        {
            if(v[g[ind][i]]) continue;
            pq.push(node(a[ind][g[ind][i]], g[ind][i]));
        }
    }
    return ret;
}

int main()
{
    cin>>m;
    int e;
    cnt = 1;
    int fk = -1;
    for(int i=0; i<m; i++)
    {
        cin>>e;
        for(int j=0; j<e; j++)
        {
            cin>>b[j];
            fk = max(fk, b[j]);
        }
        b[e] = b[0];
        int tmp;
        for(int j=0; j<e; j++)
        {
            cin>>tmp;
            int mi = min(b[j], b[j+1]);
            int ma = max(b[j], b[j+1]);
            if(c[mi][ma]==0)
            {
                c[mi][ma] = cnt;
                d[mi][ma] = tmp;
            }
            else
            {
                g[c[mi][ma]].push_back(cnt);
                g[cnt].push_back(c[mi][ma]);
                a[c[mi][ma]][cnt] = tmp;
                a[cnt][c[mi][ma]] = tmp;
                c[mi][ma] = -1;
            }
        }
        cnt++;
    }
    int ans = INF;
    ans = min(ans, prim());
    bool v2[110];
    memset(v2, 0, sizeof v2);
    v2[0] = true;
    for(int i=1; i<=fk; i++)
    {
        for(int j=i+1; j<=fk; j++)
        {
            if(c[i][j]==-1) continue;
            if(v2[c[i][j]]) continue;
            v2[c[i][j]] = true;
            g[0].push_back(c[i][j]);
            g[c[i][j]].push_back(0);
            a[c[i][j]][0] = d[i][j];
            a[0][c[i][j]] = d[i][j];
        }
    }
    ans = min(ans, prim());
    cout<<ans<<endl;
    return 0;
}

/*
4
4 1 8 9 2 1 100 100 1
4 2 9 4 3 100 100 1 1
4 8 7 6 9 1 1 100 100
4 9 6 4 5 100 1 1 100
*/

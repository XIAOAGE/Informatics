#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

typedef pair<int, int> edge;

int s;
int deg[50];
vector<edge> g[50];
bool v[2000];
stack<int> sta;

bool comp(edge u, edge v)
{
    return u.first<v.first;
}

void find_circuit(int ind, int street)
{
    sort(g[ind].begin(), g[ind].end(), comp);
    for(int i=0; i<g[ind].size(); i++)
    {
        if(!v[g[ind][i].first])
        {
            v[g[ind][i].first] = true;
            find_circuit(g[ind][i].second, g[ind][i].first);
        }
    }
    sta.push(street);
}

int main()
{
    int a, b, c;
    while(scanf("%d%d", &a, &b), a!=0 && b!=0)
    {
        memset(deg, 0, sizeof deg);
        memset(v, 0, sizeof v);
        for(int i=1; i<=44; i++) g[i].clear();
        s = min(a, b);
        scanf("%d", &c);
        deg[a]++;
        deg[b]++;
        g[a].push_back(edge(c, b));
        g[b].push_back(edge(c, a));
        while(scanf("%d%d", &a, &b), a!=0 && b!=0)
        {
            scanf("%d", &c);
            deg[a]++;
            deg[b]++;
            g[a].push_back(edge(c, b));
            g[b].push_back(edge(c, a));
        }
        bool flag = true;
        for(int i=1; i<=44; i++)
        {
            if(deg[i]%2==1)
            {
                flag = false;
                break;
            }
        }
        if(!flag) printf("Round trip does not exist.\n");
        if(!flag) continue;
        find_circuit(s, -1);
        while(!sta.empty())
        {
            if(sta.top()!=-1)cout<<sta.top()<<" ";
            sta.pop();
        }
        cout<<endl;
    }
    return 0;
}

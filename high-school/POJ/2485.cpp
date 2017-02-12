#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> node;

int T, N;
int map[500][500];
bool visited[500];

void input();

void solve()
{
    priority_queue<node, vector<node>, greater<node> > pq;
    int ans = 0;
    node start = node(0,0);
    pq.push(start);
    while(!pq.empty())
    {
        node current = pq.top(); pq.pop();
        if(visited[current.second]) continue;
        visited[current.second] = true;
        ans  = max(ans, current.first);
        for(int i=0; i<N; i++)
        {
            if(i==current.second || visited[i]) continue;
            node next = node(map[current.second][i], i);
            pq.push(next);
        }
    }
    printf("%d\n", ans);
}

int main()
{
    cin>>T;
    while(T--)
    {
        input();
        solve();
    }
}

void input()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        visited[i] = false;
        for(int j=0; j<N; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
}

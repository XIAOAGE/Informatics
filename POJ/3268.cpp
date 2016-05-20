#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <string.h>

using namespace std;
#define MAX_V 10000

struct edge
{
    int to, cost;
    edge(){}
    edge(int a, int b): to(a), cost(b){}
};

typedef pair<int, int> P;

int N, M, X;
vector<vector<edge> > G(MAX_V);
vector<vector<edge> > RG(MAX_V);
int D[MAX_V];
int RD[MAX_V];

void dijkstra(int start)
{
    priority_queue<P, vector<P>, greater<P> > qu;
    memset(D, 1000000, sizeof(D));
    D[start] = 0;
    qu.push(P(0,start));

    while(!qu.empty())
    {
        P p = qu.top(); qu.pop();
        int distance = p.first;
        int v = p.second;

        for(int i=0; i<G[v].size(); i++)
        {
            edge e = G[v][i];
            if(D[e.to]>distance+e.cost)
            {
                D[e.to] = D[v] + e.cost;
                qu.push(P(D[e.to],e.to));
            }
        }
    }
}

int main()
{
    int A, B, T;
    cin>>N>>M>>X;
    for(int i=0; i<M; i++)
    {
        cin>>A>>B>>T;
        G[A].push_back(edge(B,T));
        RG[B].push_back(edge(A,T));
    }
    dijkstra(X);
    G = RG;
    memcpy(RD,D,sizeof(D));
    dijkstra(X);
    int ans = -1;
    for(int i=1; i<=N; i++)
    {
        ans = max(ans, D[i]+RD[i]);
    }
    cout<<ans<<endl;
    return 0;
}

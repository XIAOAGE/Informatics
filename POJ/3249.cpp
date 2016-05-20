#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;

const int MAXN = 100010;
const int MAXM = 1000010;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int v;
	LL w;
	int next;
}edge[MAXM];

int n, m;
int cnt, tot;
int count2;

LL d[MAXN], w[MAXN];
int first[MAXN];
int fa[MAXN], topo[MAXN];
int ind[MAXN], outd[MAXN];
int save[MAXN];

void init()
{
	cnt = 0;
	tot = 0;
	count2 = 0;
	memset(first, -1, sizeof(first));
	memset(fa, 0, sizeof(fa));
	memset(ind, 0, sizeof(0));
	memset(outd, 0, sizeof(outd));
}

void read_graph(int u, int v, LL w)
{
	edge[cnt].v = v, edge[cnt].w = w;
	edge[cnt].next = first[u], first[u] = cnt++;
}

void toposort() //toposort
{
	queue<int> q;
	for(int i = 0; i <= n; i++) if(!ind[i]) q.push(i);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		topo[++tot] = x;
		for(int e = first[x]; e != -1; e = edge[e].next)
		{
			int v = edge[e].v;
			if(--ind[v] == 0)
			{
				q.push(v);
			}
		}
	}
}

void DAGShortestPath(int src) //DAG有向无环图的最长路径
{
	for(int i = 0; i <= n; i++) d[i] = (i == src)? 0:-INF;
	for(int u = 1; u <= tot; u++)
	{
		int x = topo[u];
		for(int e = first[x]; e != -1; e = edge[e].next)
		{
			int v = edge[e].v, w = edge[e].w;
			if(d[v] < d[x] + w)
			{
				d[v] = d[x] + w;
				fa[v] = u;
			}
		}
	}
}

void read_case()
{
	init();
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &w[i]);
	}
	while(m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		read_graph(u, v, w[v]); //点权转换为边权 
		outd[u]++;
		ind[v]++;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!outd[i]) //储存出度为0的点，即终点
		{
			save[count2++] = i;
		}
		if(!ind[i])
		{
			read_graph(0, i, w[i]); //没有入边的点需要添加一个节点0，并连接一条有向边。 
			ind[i]++;
		}
	}
}

void solve()
{
	read_case();
	toposort();
	DAGShortestPath(0);
	LL ans = -INF;
	for(int i = 0; i < count2; i++) //枚举最大值 
	{
		ans = max(ans, d[save[i]]);
	}
	
	printf("%lld\n", ans);
}

int main()
{
	while(~scanf("%d%d", &n, &m))
	{
		solve();
	}
	return 0;
}

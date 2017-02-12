#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct edge
{
    int node1, node2, cost;
};

typedef pair<int, int> node;

int t, n, m;
int map[110][110];  //边的长度
vector<int> v[110]; //邻接表
int maxd[110][110]; //记录在做小生成树上从一个点到另一个点的最大值
bool T[110][110]; //用来记录哪些边已经用过了
vector<edge> e; //放入所有的边

int MST()
{
    int ret = 0;
    priority_queue<node, vector<node>, greater<node> > pq;
    vector<int> vec;
    int father[110];
    bool visited[110];
    for(int i=1; i<=n; i++) visited[i] = false;
    for(int i=1; i<=n; i++) father[i] = -1;
    pq.push(node(0,1));
    while(!pq.empty())
    {
        node current = pq.top(); pq.pop();
        int index = current.second;
        if(visited[index]) continue;
        T[father[index]][index] = T[index][father[index]] = true;
        visited[index] = true;
        ret += current.first;
        for(int i=0; i<v[index].size(); i++)
        {
            int to = v[index][i];
            if(!visited[to])
            {
                pq.push(node(map[index][to], to));
                if(father[to]==-1 || map[father[to]][to]>map[index][to])   father[to] = index;
            }
        }
        for(int i=0; i<vec.size(); i++)
        {
            maxd[vec[i]][index] = maxd[index][vec[i]] = max(current.first, maxd[vec[i]][father[index]]);
        }
        vec.push_back(index);
    }
    return ret;
}

bool second_MST()
{
    //枚举所有不在T中的边u-v,加入边u-v,删除权值为max[u][v]的边,不断枚举找到次小生成树.
    for(int i=0; i<e.size(); i++)
    {
        if(T[e[i].node1][e[i].node2]) continue;
        //nt max_edge = maxd[e[i].node1][e[i].node2];
        //if(max_edge-e[i].cost==0) return true;
    }
    return false;
}

void solve()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            T[i][j] = false;
            maxd[i][j] = 0;
        }
    }
    int ans = MST();
    /*
    if(second_MST())
    {
        cout<<"Not Unique!"<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
    */
}

int main()
{
    cin>>t;
    while(t--)
    {
        e.clear();
        for(int i=1; i<=n; i++) v[i].clear();
        cin>>n>>m;
        int a, b, c;
        for(int i=0; i<m; i++)
        {
            cin>>a>>b>>c;
            map[a][b] = map[b][a] = c;
            edge tmp = {a, b, c};
            e.push_back(tmp);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        solve();
    }
    return 0;
}
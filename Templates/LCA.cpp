/*
    Make Table: O(NlogN)
    Query: O(logN)

    The code is the solution to POJ 1330

    P[i][j] --> is the 2^j-th ancestor of i
*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int t, n, root;
int P[10010][20];
int L[10010];
bool mark[10010]; //for getting the root of the tree
vector<int> G[10010];

//To get the depth for each tree node
void dfs(int index,int lv)
{
    L[index] = lv;
    for(int i=0; i<G[index].size(); i++)
        dfs(G[index][i], lv+1);
}

//In this sample problem, root is not given, so I have to use mark
int get_root()
{
    for(int i=1; i<=n; i++)
        if(!mark[i])
            return i;
    return -1;
}

//####################main part###########################
void pre_solve()
{
    for(int i=1; i<=n; i++)
        for(int j=0; 1<<j<n; j++)
            P[i][j] = -1;

    int a, b;
    for(int i=1; i<n; i++)
    {
        scanf("%d%d", &a, &b);  //read in 2 nodes, an edge from a to b
        mark[b] = true;
        G[a].push_back(b);
        P[b][0] = a;        //b's 2^0th ancestor is a  
    }
    
    for(int j=1; 1<<j<n; j++)
        for(int i=1; i<=n; i++)
            if(P[i][j-1]!=-1)
                P[i][j] = P[P[i][j-1]][j-1];
}

int query(int u, int v)
{
    //we want u's depth is >= v.
    int log;
    if(L[u]<L[v])   swap(u, v);
    
    //find the distance to root
    for(log=1; 1<<log<=L[u]; log++);
    log--;
    
    //work similar to binary search
    //we make the depth of u and v equal.
    for(int i=log; i>=0; i--)
        if(L[u]-(1<<i)>=L[v])
            u = P[u][i];
    
    if(u==v) return u;
    //another binary search
    //when u and v are at the same height, easy to find LCA.
    for(int i=log; i>=0; i--)
        if(P[u][i]!=-1 && P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    
    return P[u][0];
}
//########################################################

void init()
{
    for(int i=1; i<=n; i++)
    {
        mark[i] = false;
        G[i].clear();
    }
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        init();
        pre_solve();
        root = get_root();
        dfs(root,0);
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", query(a, b));
    }
    return 0;
}

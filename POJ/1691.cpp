#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct rect
{
    int ly, lx, ry, rx, color;
};

int M, N;
vector<int> graph[15];
rect arr[15];
int indegree[15];
int ans;

void input();

void solve(int color, vector<int> next, int res, int cnt)
{
    if(res>=ans) return;
    if(cnt==N)
    {
        ans = min(ans, res);
        return;
    }
    
    for(int i=0; i<next.size(); i++)
    {
        vector<int> for_next;
        for(int j=0; j<next.size(); j++)
        {
            if(i==j) continue;
            for_next.push_back(next[j]);
        }
        for(int j=0; j<graph[next[i]].size(); j++)
        {
            if(!(--indegree[graph[next[i]][j]]))
            {
                for_next.push_back(graph[next[i]][j]);
            }
        }
        if(arr[next[i]].color!=color) res++;
        solve(arr[next[i]].color, for_next, res, cnt+1);
        if(arr[next[i]].color!=color) res--;
        for(int j=0; j<graph[next[i]].size(); j++)
        {
            indegree[graph[next[i]][j]]++;
        }
    }
}

int main()
{
    cin>>M;
    while(M--)
    {
        input();
        ans = 2147483647;
        vector<int> start;
        for(int i=0; i<N; i++)
        {
            if(!indegree[i]) start.push_back(i);
        }
        solve(-1,start,0,0);
        cout<<ans<<endl;
    }
    return 0;
}

void init()
{
    for(int i=0; i<15; i++)
    {
        graph[i].clear();
        arr[i] = {};
        indegree[i] = 0;
    }
}

void input()
{
    cin>>N;
    int a, b, c, d, e;
    init();
    for(int i=0; i<N; i++)
    {
        cin>>a>>b>>c>>d>>e;
        arr[i] = {a,b,c,d,e};
    }
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(arr[i].ry==arr[j].ly)
            {
                if(!(arr[j].rx<=arr[i].lx || arr[j].lx>=arr[i].rx))
                {
                    graph[i].push_back(j);
                    indegree[j]++;
                }
            }
        }
    }
}

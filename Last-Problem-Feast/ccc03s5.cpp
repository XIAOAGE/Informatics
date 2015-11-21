/*
look out! in prim algorithm, everytime it will choose the maximum/minium edge!!! so take advantage of it!!!!
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> node;

int c, r, d;
vector<node> vec[10010];
int val[10010];
bool v1[10010];

int main()
{
    cin>>c>>r>>d;
    int u, v, y;
    for(int i=0; i<r; i++)
    {
        cin>>u>>v>>y;
        vec[u].push_back(node(v, y));
        vec[v].push_back(node(u, y));
    }
    priority_queue<node> pq;
    pq.push(node(100000, 1));
    while(!pq.empty())
    {
        node cur = pq.top(); pq.pop();
        int ind = cur.second;
        if(v1[ind]) continue;
        val[ind] = cur.first;
        v1[ind] = true;
        for(int i=0; i<vec[ind].size(); i++)
        {
            if(v1[vec[ind][i].first]) continue;
            pq.push(node(vec[ind][i].second, vec[ind][i].first));
        }
    }
    int ans = 0x3f3f3f3f;
    int tmp;
    for(int i=0; i<d; i++)
    {
        cin>>tmp;
        ans = min(ans, val[tmp]);
    }
    cout<<ans<<endl;
    return 0;
}

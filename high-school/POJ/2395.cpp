#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> node;

int N, M;
vector<pair<int, int> > arr[2010];
bool used[2010];

int main()
{
    cin>>N>>M;
    int a, b, c;
    for(int i=0; i<M; i++)
    {
        cin>>a>>b>>c;
        arr[a].push_back(make_pair(c, b));
        arr[b].push_back(make_pair(c, a));
    }
    
    priority_queue<node, vector<node>, greater<node> > pq;
    pq.push(node(0,1));
    int ans = -1;
    while(!pq.empty())
    {
        node current = pq.top(); pq.pop();
        int number = current.second;
        if(used[number]) continue;
        used[number] = true;
        ans = max(ans, current.first);
        for(int i=0; i<arr[number].size(); i++)
        {
            if(!used[arr[number][i].second]) pq.push(node(arr[number][i].first, arr[number][i].second));
        }
    }
    
    cout<<ans<<endl;
    return 0;
}

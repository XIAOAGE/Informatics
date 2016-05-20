#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> node;

int N, M;
bool used[1010];
vector<pair<int, int> > arr[1010];

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
    
    priority_queue<node> pq;
    int ans = 0;
    pq.push(node(0, 1));
    int cnt = 0;

    while(!pq.empty())
    {
        node current = pq.top(); pq.pop();
        int number = current.second;
        if(used[number]) continue;
        cnt++;
        ans += current.first;
        used[number] = true;
        for(int i=0; i<arr[number].size(); i++)
        {
            if(!used[arr[number][i].second])    pq.push(node(arr[number][i].first,arr[number][i].second));
        }
    }
    if(cnt!=N) ans = -1;
    cout<<ans<<endl;
    return 0;
}

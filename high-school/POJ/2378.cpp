#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr[10010];
vector<int> ans;
int son[10010];

int dfs(int index, int pre)
{
    int ret = 1;
    bool right = true;
    for(int i=0; i<arr[index].size(); i++)
    {
        if(arr[index][i]==pre) continue;
        int tmp = dfs(arr[index][i], index);
        ret += tmp;
        if(right) right = tmp <= (n/2);
    }
    if(right) right = (n-ret) <= (n/2);
    if(right) ans.push_back(index);
    son[index] = ret;
    return son[index];
}

int main()
{
    cin>>n;
    int a, b;
    for(int i=0; i<n-1; i++)
    {
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1, -1);
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}

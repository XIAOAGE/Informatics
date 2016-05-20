#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;
int node1, node2;
int root;
int tree[10001];
vector<int> arr[10001];

void input();

int solve(int current)
{
    int res = 0;
    if(current == node1 || current == node2)
    {
        res += 1;
    }
    for(int i=0; i<arr[current].size(); i++)
    {
        res += solve(arr[current][i]);
    }
    if(res > 2) return 3;
    if(res == 2)
    {
        cout<<current<<endl;
        return 3;
    }
    return res;
}

int main()
{
    cin>>T;
    while(T--)
    {
        input();
        solve(root);
    }
    return 0;
}

void input()
{
    for(int i=0; i<=10001; i++)
    {
        tree[i] = -1;
        arr[i].clear();
    }
    cin>>N;
    int a, b;
    for(int i=0; i<N-1; i++)
    {
        cin>>a>>b;
        tree[b] = a;
        arr[a].push_back(b);
    }
    for(int i=1; i<=N; i++)
    {
        if(tree[i]==-1)
        {
            root = i;
            break;
        }
    }
    cin>>node1>>node2;
}

#include <iostream>

#define endl "\n"

using namespace std;

int n,q;
int arr[50010];
int max_tree[200001];
int min_tree[200001];

int build_min_tree(int root, int left, int right)
{
    if(left==right)
    {
        min_tree[root] = arr[left];
        return arr[left];
    }
    int mid = (left+right)/2;
    min_tree[root] = min(build_min_tree(root*2, left, mid), build_min_tree(root*2+1, mid+1, right));
    return min_tree[root];
}

int build_max_tree(int root, int left, int right)
{
    if(left==right)
    {
        max_tree[root] = arr[left];
        return arr[left];
    }
    int mid = (left+right)/2;
    max_tree[root] = max(build_max_tree(root*2, left, mid), build_max_tree(root*2+1, mid+1, right));
    return max_tree[root];
}

int max_query(int root, int left, int right, int l, int r)
{
    if(l>right || r<left) return -1;
    if(left>=l && right<=r) return max_tree[root];
    int mid = (left+right)/2;
    return max(max_query(root*2, left, mid, l, r), max_query(root*2+1, mid+1, right, l, r));
}

int min_query(int root, int left, int right, int l, int r)
{
    if(l>right || r<left) return 2147483647;
    if(left>=l && right<=r) return min_tree[root];
    int mid = (left+right)/2;
    return min(min_query(root*2, left, mid, l, r), min_query(root*2+1, mid+1, right, l, r));
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    build_min_tree(1, 0, n-1);
    build_max_tree(1, 0, n-1);
    int a, b;
    while(cin>>a>>b)
    {
        cout<<max_query(1, 0, n-1, a-1, b-1)-min_query(1, 0, n-1, a-1, b-1)<<endl;
    }
    return 0;
}

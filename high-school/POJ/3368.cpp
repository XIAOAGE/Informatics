#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> node;
struct s
{
    int left, right, mid, val;
};
int n, q;
s tree[200020];
vector<node> vec;

void build_tree(int root, int l, int r)
{
    if(l==r)
    {
        s tmp = {vec[l].first, vec[l].second, -1, vec[l].second-vec[l].first+1};
        tree[root] = tmp;
        return;
    }
    int m = (l+r)/2;
    build_tree(root<<1, l, m);
    build_tree(root<<1|1, m+1, r);
    s tmp = {tree[root<<1].left, tree[root<<1|1].right, tree[root<<1].right, max(tree[root<<1].val,tree[root<<1|1].val)};
    tree[root] = tmp;
}

int query(int root, int l, int r, int start, int end)
{
    if(tree[root].mid==-1)  return end-start+1;
    if(tree[root].left==start && tree[root].right==end) return tree[root].val;
    int m = (l+r)/2;
    if(tree[root].mid<start)    return query(root<<1|1, m, r, start, end);
    else if(tree[root].mid>=end)    return query(root<<1, l, m, start, end);
    else    return max(query(root<<1, l, m, start, tree[root].mid), query(root<<1|1, m+1, r, tree[root].mid+1, end));
}

void init()
{
    int tmp1, tmp2;
    int start=0, end=0;
    scanf("%d", &tmp1);
    for(int i=1; i<n; i++)
    {
        scanf("%d", &tmp2);
        if(tmp1==tmp2) end++;
        else
        {
            vec.push_back(node(start, end));
            start = end+1;
            end = end+1;
            tmp1 = tmp2;
        }
    }
    vec.push_back(node(start, end));
}

int main()
{
    while(scanf("%d", &n), n)
    {
        scanf("%d", &q);
        vec.clear();
        init();
        build_tree(1, 0, (int)vec.size()-1);
        int a, b;
        for(int i=0; i<q; i++)
        {
            scanf("%d%d", &a,&b);
            cout<<query(1, 0, (int)vec.size()-1, a-1, b-1)<<endl;
        }
    }
    return 0;
}

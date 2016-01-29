#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> node;

int n;
int a[100010];
node tree[400010];

void push_down(int idx)
{
    if(tree[idx].second!=0)
    {
        tree[idx<<1].first += tree[idx].second;
        tree[idx<<1|1].first += tree[idx].second;
        tree[idx<<1].second += tree[idx].second;
        tree[idx<<1|1].second += tree[idx].second;
        tree[idx].second = 0;
    }
}

void update(int idx, int l, int r, int s, int e, int v)
{
    if(l==s && r==e)
    {
        tree[idx].first += v;
        if(l!=r) tree[idx].second += v;
        return;
    }
    int m = (l+r)/2;
    push_down(idx);
    if(m>=s && m<e)
    {
        update(idx<<1, l, m, s, m, v);
        update(idx<<1|1, m+1, r, m+1, e, v);
    }
    else if(e<=m) update(idx<<1, l, m, s, e, v);
    else if(s>m) update(idx<<1|1, m+1, r, s, e, v);
    tree[idx].first = min(tree[idx<<1].first, tree[idx<<1|1].first);
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for(int i=2; i<=n; i+=2)
    {
        if(i!=2) update(1, 1, n, 1, a[i/2], 2);
        else update(1, 1, n, 1, a[i/2], 1);
        update(1, 1, n, 1, a[i], -1);
        if(i!=2) update(1, 1, n, 1, a[i-1], -1);
        if(tree[1].first>=0) ans = i/2;
    }
    printf("%d\n", ans);
    return 0;
}

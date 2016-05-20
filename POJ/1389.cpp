#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
    int l, r, ml, mr, s, len;
};

struct edge
{
    int y, x1, x2, flag;
};

int x1, y1, x2, y2;
node tree[10000];
edge e[3000];
bool used[50010];
int x[3000];
int cnt1, cnt2;

bool cmp(edge a, edge b)
{
    return a.y<b.y;
}

void build_tree(int root, int left, int right)
{
    tree[root].l = left;
    tree[root].r = right;
    tree[root].ml = x[left];
    tree[root].mr = x[right];
    tree[root].len = 0;
    tree[root].s = 0;
    if(tree[root].l+1==tree[root].r) return;
    int mid = (left+right)>>1;
    build_tree(root<<1, left, mid);
    build_tree(root<<1|1, mid, right);
}

void cal_len(int root)
{
    if(tree[root].s>0)  tree[root].len = tree[root].mr-tree[root].ml;
    else if(tree[root].r-tree[root].l==1)   tree[root].len = 0;
    else    tree[root].len = tree[root<<1].len + tree[root<<1|1].len;
}

void update(int root, edge eg)
{
    if(tree[root].ml==eg.x1 && tree[root].mr==eg.x2)
    {
        tree[root].s += eg.flag;
        cal_len(root);
        return;
    }
    if(tree[root<<1].mr>=eg.x2) update(root<<1, eg);
    else if(tree[root<<1|1].ml<=eg.x1) update(root<<1|1, eg);
    else
    {
        edge next = eg;
        next.x2 = tree[root<<1].mr;
        update(root<<1, next);
        next = eg;
        next.x1 = tree[root<<1|1].ml;
        update(root<<1|1, next);
    }
    cal_len(root);
}

int main()
{
    while(scanf("%d%d%d%d", &x1, &y1, &x2, &y2), x1!=-1 && y1!=-1 && x2!=-1 && y2!=-1)
    {
        cnt1 = 0;
        cnt2 = 0;
        for(int i=0; i<50010; i++) used[i] = false;
        x[cnt1++] = x1;
        e[cnt2++] = {y1, x1, x2, 1};
        x[cnt1++] = x2;
        e[cnt2++] = {y2, x1, x2, -1};
        while(scanf("%d%d%d%d", &x1, &y1, &x2, &y2), x1!=-1 && y1!=-1 && x2!=-1 && y2!=-1)
        {
            if(!used[x1])
            {
                x[cnt1++] = x1;
                used[x1] = true;
            }
            e[cnt2++] = {y1, x1, x2, 1};
            
            if(!used[x2])
            {
                x[cnt1++] = x2;
                used[x2] = true;
            }
            e[cnt2++] = {y2, x1, x2, -1};
        }
        sort(x, x+cnt1);
        sort(e, e+cnt2, cmp);
        build_tree(1, 0, cnt1-1);
        update(1, e[0]);
        int ans = 0;
        for(int i=1; i<cnt2; i++)
        {
            ans += tree[1].len * (e[i].y-e[i-1].y);
            update(1, e[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX_LEN 200010
struct node
{
    int left;
    int right;
    int color;
    int sign;
};
node tree[MAX_LEN*2];
int sum;
int makeTree(int left,int right,int k)
{
    int mid;
    tree[k].color=1;
    tree[k].left=left;
    tree[k].right=right;
    tree[k].sign=0;
    if(left==right) return 0;
    mid=(left+right)>>1;
    makeTree(left,mid,k<<1);
    makeTree(mid+1,right,(k<<1)+1);
    return 0;
}
inline int push(int k)
{
    tree[k].sign=0;
    if(tree[k].left<tree[k].right)
    {
        tree[k<<1].color=tree[k].color;
        tree[(k<<1)+1].color=tree[k].color;
        tree[k<<1].sign=tree[(k<<1)+1].sign=1;
    }
    return 0;
}
int tintage(int left,int right,int color,int k)
{
    int mid;
    if(tree[k].left==left && tree[k].right==right)
    {
        tree[k].color=1<<(color-1);
        tree[k].sign=1;
        return 0;
    }
    if(tree[k].sign)  push(k);
    mid=(tree[k].left+tree[k].right)>>1;
    if(right<=mid)
        tintage(left,right,color,k<<1);
    else if(left>mid)
        tintage(left,right,color,(k<<1)+1);
    else
    {
        tintage(left,mid,color,k<<1);
        tintage(mid+1,right,color,(k<<1)+1);
    }
    tree[k].color=tree[k<<1].color|tree[(k<<1)+1].color;
    return 0;
}
int calculate(int color)
{
    int i,j=1,k=0;
    for(i=0;i<30;j=(1<<++i))
        if(color&j) k++;
    return k;
}
int query(int left,int right,int k)
{
    int mid;
    if(tree[k].left==left && tree[k].right==right)
    {
        sum=sum|tree[k].color;
        return 0;
    }
    if(tree[k].sign) push(k);
    mid=(tree[k].left+tree[k].right)>>1;
    if(right<=mid)
        query(left,right,k<<1);
    else if(left>mid)
        query(left,right,(k<<1)+1);
    else
    {
        query(left,mid,k<<1);
        query(mid+1,right,(k<<1)+1);
    }
    return 0;
}
int main()
{
    int i,m,n,len,color,left,right,temp;
    char c[10];
    while(scanf("%d%d%d",&len,&m,&n)!=EOF)
    {
        makeTree(1,len,1);
        for(i=0;i<n;i++)
        {
            scanf("%s",c);
            if(c[0]=='C')
            {
                scanf("%d%d%d",&left,&right,&color);
                if(left>right) {temp=left,left=right,right=temp;}
                tintage(left,right,color,1);
            }
            if(c[0]=='P')
            {
                sum=0;
                scanf("%d%d",&left,&right);
                if(left>right) {temp=left,left=right,right=temp;}
                query(left,right,1);
                printf("%d\n",calculate(sum));
            }
        }
    }
    return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;

#define lson l,m,root<<1
#define rson m+1,r,root<<1|1
#define MAXN 10000

int n;
int node[MAXN<<2];
int a[MAXN],b[MAXN];
void push_up(int root)
{
	node[root]=node[root<<1]+node[root<<1|1];
}

void build(int l,int r,int root)
{
	if(l==r)
	{
		node[root]=1;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	push_up(root);
}

int query(int p,int l,int r,int root)
{
	if(l==r)
	{
		node[root]=0;
		return l;
	}
	int m=(l+r)>>1;
	int ret=0;
	if(p<=node[root<<1])
		ret=query(p,lson);
	else
		ret=query(p-node[root<<1],rson);
	push_up(root);
	return ret;		
}

void solve()
{
	build(1,n,1);
	for(int i=2;i<=n;i++)
		scanf("%d",&a[i]);
	a[1]=0;
	for(int i=n;i>=1;i--)
		b[i]=query(a[i]+1,1,n,1);
	for(int i=1;i<=n;i++)
		printf("%d\n",b[i]);
}

int main()
{
	while(scanf("%d",&n)!=EOF)
		solve();
	return 0;
} 

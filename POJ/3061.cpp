#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100000+10;
const int INF=0x7fffffff;
int a[MAXN],sum[MAXN];
int search(int L,int R,int target) //(L,R]
{
	while(L<R-1)
	{
		int m=(L+R)>>1;
		if(sum[m]<target)
			L=m;
		else
			R=m;
	}
	return R;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,tot;
		scanf("%d%d",&n,&tot);
		sum[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}	
		int ans=INF;
		for(int i=1;i<=n&&sum[i]+tot<=sum[n];i++)
		{
			int t=search(i,n,tot+sum[i]);//sum[t]-sum[i]>=tot -> sum[t]>=tot+sum[i]
			ans=min(ans,t-i);
		}
		if(ans==INF)
			printf("0\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}

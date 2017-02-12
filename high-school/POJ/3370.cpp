#include<iostream>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include<cstring>
using namespace std;
const int N=100009;
int n,m;
int a[N];
int sum[N];
int hash[N];
int main()
{
	while(scanf("%d%d",&n,&m),n+m)
	{
		memset(hash,0,sizeof(hash));
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
		}
		int s=1,t=1;
		sum[0]=0;
		for(int i=1;i<=m;i++)
		{
			sum[i]=(sum[i-1]+a[i])%n;
			//cout<<i<<" "<<sum[i]<<endl;
			if(sum[i]==0)
			{
				t=i;
				break;
			}
			if(hash[sum[i]]>0)
			{
				s=hash[sum[i]]+1;
				t=i;
				break;
			}
			hash[sum[i]]=i;
		}
		for(int i=s;i<t;i++)
		printf("%d ",i);
		printf("%d\n",t);
	}
return 0;
}

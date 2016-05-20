#include <iostream>
using namespace std;
int dp[100001],num[100001];
const int MINNUM = -99999999;
int main(){
	int cases,n,temp,i,sum,ans;
	cin>> cases;
	while(cases--){
		scanf("%d",&n);
		temp = MINNUM;
		sum = 0;
		for (i = 1;i <= n;i++)
		{
			scanf("%d",&num[i]);
			//先从左向右求最大子段和
			sum += num[i];
			if(sum > temp)
				temp = sum;
			dp[i] = temp;
			if (sum < 0)
				sum = 0;
		}
			
			//在从右向左找右边的字段和与左边字段和最大值
			temp = ans = MINNUM;
			sum = 0;
			for (i = n;i > 1;i--)
			{
				sum += num[i];
				if (sum > temp)
					temp = sum;
				if (ans < dp[i-1] + temp)
					ans = dp[i-1] + temp;
				if (sum < 0)
					sum = 0;
			}	
			cout<<ans<<endl;
	}
	return 0;
}

//Memory Time 
//656K  16MS 

/*多重背包+二进制优化*/

#include<iostream>
using namespace std;

int n[7];  //价值为i的物品的个数
int v;  //背包容量
int SumValue;  //物品总价值
bool flag;    //标记是否能平分SumValue
int dp[100000];  //状态数组

int max(int a,int b)
{
	return a>b?a:b;
}

/*完全背包*/
void CompletePack(int cost,int weight)
{
	for(int i=cost;i<=v;i++)
	{
		dp[i]=max(dp[i],dp[i-cost]+weight);
		if(dp[i]==v)    //剪枝，当能够平分SumValue时退出
		{
			flag=true;
			return;
		}
	}
			
	return;
}

/*01背包*/
void ZeroOnePack(int cost,int weight)
{
	for(int i=v;i>=cost;i--)
	{
		dp[i]=max(dp[i],dp[i-cost]+weight);
		if(dp[i]==v)    //剪枝
		{
			flag=true;
			return;
		}
	}
	return;
}

/*多重背包*/
void MultiplePack(int cost,int weight,int amount)
{
	if(cost*amount>=v)
	{
		CompletePack(cost,weight);
		return;
	}

	if(flag)    //剪枝
		return;

	/*二进制优化*/
	int k=1;
	while(k<amount)
	{
		ZeroOnePack(k*cost,k*weight);

		if(flag)    //剪枝
			return;

		amount-=k;
		k*=2;
	}
	ZeroOnePack(amount*cost,amount*weight);

	return;
}

int main(int i)
{
	int test=1;
	while(cin>>n[1]>>n[2]>>n[3]>>n[4]>>n[5]>>n[6])
	{
		SumValue=0;  //物品总价值

		for(i=1;i<=6;i++)
			SumValue+=i*n[i];

		if(SumValue==0)
			break;

		if(SumValue%2)    //sum为奇数，无法平分
		{
			cout<<"Collection #"<<test++<<':'<<endl;
			cout<<"Can't be divided."<<endl<<endl;    //注意有空行
			continue;
		}

		v=SumValue/2;
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		flag=false;

		for(i=1;i<=6;i++)
		{
			MultiplePack(i,i,n[i]);

			if(flag)    //剪枝
				break;
		}

		if(flag)
		{
			cout<<"Collection #"<<test++<<':'<<endl;
			cout<<"Can be divided."<<endl<<endl;
			continue;
		}
		else
		{
			cout<<"Collection #"<<test++<<':'<<endl;
			cout<<"Can't be divided."<<endl<<endl;
			continue;
		}
	}
	return 0;
}

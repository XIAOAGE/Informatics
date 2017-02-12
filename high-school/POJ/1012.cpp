/*约瑟夫环*/
#include <iostream>

using namespace std;

int main()
{
	int Joseph[14] = {0};	//Joseph环
	int k;
	while(cin>>k)
	{
		if (k == 0)
		{
			break;
		}

		if (Joseph[k])
		{
			cout<<Joseph[k]<<endl;
			continue;
		}

		int num;	//人数
		num = 2 * k;

		int kill[30] = {0};	//杀掉的人

		int m = 1;	//报数
		for (int i = 1; i <= k; i++)
		{
			kill[i] = (kill[i - 1] + m - 1) % (num - i + 1);	//从1开始计数计算Joseph环算法
			if (kill[i] < k)	//杀死的是好人
			{
				m ++;
				i = 0;
			}
		}
		Joseph[k] = m;
		cout<<m<<endl;
	}
	return 0;
}

/*
题意： 农夫约翰要找他的牛， 每一分钟他和牛都只能沿着当前方向向前走一格，如果遇到边界或者是障碍物就必须花一分钟向顺时针的方向走一步。
      问多少分钟约翰能抓到牛。

思路： 一共有100个格子， 每个格子有四种不同的方向， 所以两个人最多花160000才能相遇（相当于最大循环节是160000）， 模拟前160000分钟的两个人走路，
      如果枚举不出两个人在同一个格子，就gg了~~~
*/

/*
ID: qiangbr1
LANG: C++11
TASK: ttwo
*/

#define USACO
#define FILEIN "ttwo.in"
#define FILEOUT "ttwo.out"
#include <iostream>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int map[10][10];
int cowX, cowY;
int farmerX, farmerY;
string line;

void input()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> line;
		for (int j = 0; j < 10; j++)
		{
			if (line[j] == '.')
			{
				map[i][j] = 0;
			}
			else if (line[j] == '*')
			{
				map[i][j] = 1;
			}
			else if (line[j] == 'C')
			{
				cowX = i;
				cowY = j;
				map[i][j] = 0;
			}
			else if (line[j] == 'F')
			{
				farmerX = i;
				farmerY = j;
				map[i][j] = 0;
			}
		}
	}
}

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void solve()
{
	int time = 0;
	int cow_dir = 0;
	int fam_dir = 0;
	while (time <= 160000)
	{
		if (cowX == farmerX && cowY == farmerY) break;
		int nextX, nextY;
		nextX = cowX + dx[cow_dir];
		nextY = cowY + dy[cow_dir];
		if (!(nextX >= 0 && nextX < 10 && nextY >= 0 && nextY < 10) || map[nextX][nextY])
		{
			cow_dir = (cow_dir + 1) % 4;
		}
		else
		{
			cowX = nextX;
			cowY = nextY;
		}
		nextX = farmerX + dx[fam_dir];
		nextY = farmerY + dy[fam_dir];
		if (!(nextX >= 0 && nextX < 10 && nextY >= 0 && nextY < 10) || map[nextX][nextY])
		{
			fam_dir = (fam_dir + 1) % 4;
		}
		else
		{
			farmerX = nextX;
			farmerY = nextY;
		}
		time++;
	}
	if(time==160001) time = 0;
	cout << time << endl;
}

int main()
{
#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
#endif
	input();
	solve();
	return 0;
}

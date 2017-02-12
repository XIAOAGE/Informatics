/*
题意： 就是给你一个宽W，高H的一个迷宫和两个出口， 问你在迷宫中任何一个点出发，最长需要几步。
思路： 最恶心的模拟题， 注意是练习写代码和练习注意力。 由于输入很有（dan）趣（teng）， 我就直接把整个输入一起读入
      因为连边什么的我觉得代码还会更长。 全部读入后发现小地图上的坐标和大地图上是除以2进行了（C++会帮你把.5剔除）。
      然后就简单了。
*/

/*
ID: qiangbr1
LANG: C++11
TASK: maze1
*/

#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

#define USACO
#define FILEIN "maze1.in"
#define FILEOUT "maze1.out"

struct pos
{
	int x, y,step;
};

using namespace std;

const int MAX_W = 500;
const int MAX_H = 500;
int W, H;
int startX, startY;
string line;
int map[2*MAX_H][2*MAX_W];
bool visited[MAX_H][MAX_W];
int ans1[MAX_H][MAX_W];
int ans2[MAX_H][MAX_W];
void input();

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void check(int x, int y, int flag)
{
	int ans[MAX_H][MAX_W];
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			ans[i][j] = 0;
		}
	}
	pos start = { x, y, 1};
	ans[x / 2][y / 2] = 1;
	visited[x / 2][y / 2] = true;
	queue<pos> qu;
	qu.push(start);
	while (!qu.empty())
	{
		pos current = qu.front(); qu.pop();
		int realX = current.x / 2;
		int realY = current.y / 2;
		int fstep = current.step;
		for (int i = 0; i < 4; i++)
		{
			int nextX = realX + dx[i];
			int nextY = realY + dy[i];
			if (nextX >= 0 && nextX < H && nextY >= 0 && nextY < W && map[current.x + dx[i]][current.y + dy[i]] && !visited[nextX][nextY])
			{
				pos next = { current.x + dx[i] * 2, current.y + dy[i] * 2, fstep + 1 };
				visited[nextX][nextY] = true;
				ans[nextX][nextY] = next.step;
				qu.push(next);
			}
		}
	}
	if (!flag)
	{
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				ans1[i][j] = ans[i][j];
			}
		}
	}
	else
	{
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				ans2[i][j] = ans[i][j];
			}
		}
	}
}

void init()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			visited[i][j] = false;
		}
	}
}

int solve()
{
	int res = -1;
	int flag = 0;
	for (int i = 0; i <= 2 * W; i++)
	{
		if (map[0][i])
		{
			init();
			check(1, i, flag);
			flag++;
		}
		if (map[2 * H][i])
		{
			init();
			check(2 * H-1, i, flag);
			flag++;
		}
	}

	for (int i = 0; i <= 2 * H; i++)
	{
		if (map[i][0])
		{
			init();
			check(i, 1, flag);
			flag++;
		}
		if (map[i][2 * W])
		{
			init();
			check(i, 2 * W - 1, flag);
			flag++;
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			res = max(res, min(ans1[i][j], ans2[i][j]));
		}
	}
	return res;
}

int main()
{
#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
#endif
	cin >> W >> H;
	getline(cin, line);
	input();
	int ans = solve();
	cout << ans << endl;
	return 0;
}

void input()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			visited[i][j] = false;
		}
	}

	for (int i = 0; i <= 2 * H; i++)
	{
		getline(cin, line);
		for (int j = 0; j <= 2 * W; j++)
		{
			if (line[j] == ' ')
			{
				map[i][j] = 1;
			}
			else
			{
				map[i][j] = 0;
			}
		}
	}
}

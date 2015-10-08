/*
 题意：找出R*C的图中不想交的矩形个数，如果有一个相交矩形就输出Bad placement. 不然就输出能放多少船
 
 不相交是说对于一个矩形（‘#’组成）周围一圈都是由‘.’包围，所以我们只用求出以某个点为起点的最大和最小的x,y的值，并且在搜索时‘#’的个数rec，如果rec=（maxx-minx+1)*(maxy-miny+1)成立，则这个矩形合法
 要用gets输入否则TLE
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int R, C;
int map[1000][1000];
bool visited[1000][1000];
int cnt;
int minX, minY;
int maxX, maxY;

void input();

int dx[] = {-1,0,0,1,-1,-1,1,1};
int dy[] = {0,1,-1,0,1,-1,1,-1};

void dfs(int x, int y)
{
    cnt++;
    for(int i=0; i<8; i++)
    {
        int nextX = x+dx[i];
        int nextY = y+dy[i];
        if(nextX>=0 && nextX<R && nextY>=0 && nextY<C && !visited[nextX][nextY] && map[nextX][nextY])
        {
            maxX = max(maxX, nextX);
            maxY = max(maxY, nextY);
            minX = min(minX, nextX);
            minY = min(minY, nextY);
            visited[nextX][nextY] = true;
            dfs(nextX, nextY);
        }
    }
}

void solve()
{
    int ans = 0;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(map[i][j] && !visited[i][j])
            {
                cnt = 0;
                maxX = minX = i;
                maxY = minY = j;
                visited[i][j] = true;
                dfs(i, j);
                if((maxX-minX+1)*(maxY-minY+1)!=cnt)
                {
                    cout<<"Bad placement."<<endl;
                    return;
                }
                ans++;
            }
        }
    }
    cout<<"There are "<<ans<<" ships."<<endl;
    return;
}

int main()
{
    while(cin>>R>>C, R&&C)
    {
        input();
        solve();
    }
    return 0;
}

void input()
{
    cin.ignore();
    char line[1000];
    for(int i=0; i<R; i++)
    {
        gets(line);
        for(int j=0; j<C; j++)
        {
            visited[i][j] = false;
            if(line[j]=='.')
            {
                map[i][j] = 0;
            }
            else
            {
                map[i][j] = 1;
            }
        }
    }
}
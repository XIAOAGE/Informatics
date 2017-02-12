#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

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

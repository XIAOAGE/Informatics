#include <stdio.h>
#include <iostream>

using namespace std;

bool dfs(int x, int y);
const int MAX_N = 102;
int row, col;
int map[MAX_N][MAX_N];
bool mark[MAX_N][MAX_N];
int dx[8] = {1,1,1,0,-1,-1,-1,0};
int dy[8] = {1,0,-1,-1,-1,0,1,1};

int main()
{
    while(~scanf("%d %d", &row, &col))
    {
        getchar();
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                char cha;
                scanf("%c", &cha);
                if(cha=='W'){
                    map[i][j] = 1;
                }else{
                    map[i][j] = 0;
                }
            }
            getchar();
        }
        int ans = 0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(map[i][j]==1 && dfs(i,j))
                {
                    ans += 1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

bool dfs(int x, int y)
{
    if(mark[x][y])
    {
        return false;
    }
    mark[x][y] = true;
    for(int i=0; i<8; i++)
    {
        int nextX = x+dx[i];
        int nextY = y+dy[i];
        if(nextX>=0 && nextY>=0 && nextX<row && nextY<col && map[nextX][nextY]==1)
        {
            dfs(nextX, nextY);
        }
    }
    return true;
}




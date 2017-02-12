#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int x, y, step;
    bool operator < (const node &b) const
    {
         return step>b.step;
    }
};

int m, n;
int g[310][310];
int sx, sy, ex, ey;
bool visited[310][310];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int main()
{
    while(scanf("%d%d", &m, &n), m!=0 && n!=0)
    {
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                visited[i][j] = false;
        getchar();
        string line;
        for(int i=0; i<m; i++)
        {
            getline(cin, line);
            for(int j=0; j<n; j++)
            {
                if(line[j]=='Y')
                {
                    ex = i;
                    ey = j;
                    g[i][j] = 1;
                }
                else if(line[j]=='T')
                {
                    sx = i;
                    sy = j;
                }
                else if(line[j]=='S'||line[j]=='R') g[i][j] = -1;
                else if(line[j]=='B') g[i][j] = 2;
                else if(line[j]=='E') g[i][j] = 1;
            }
        }
        priority_queue<node> pq;
        pq.push({sx, sy, 0});
        int ans = -1;
        visited[sx][sy] = true;
        while(!pq.empty())
        {
            node cur = pq.top(); pq.pop();
            int x = cur.x;
            int y = cur.y;
            int step = cur.step;
            if(x==ex && y==ey)
            {
                ans = step;
                break;
            }
            for(int i=0; i<4; i++)
            {
                int nxtX = x+dx[i];
                int nxtY = y+dy[i];
                if(nxtX<m && nxtX>=0 && nxtY<n && nxtY>=0 && !visited[nxtX][nxtY] && g[nxtX][nxtY]!=-1)
                {
                    visited[nxtX][nxtY] = true;
                    pq.push({nxtX, nxtY, step+g[nxtX][nxtY]});
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

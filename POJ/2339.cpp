#include <iostream>
#include <string>

using namespace std;

int t, r, c, n;
char map[100][100];

void input();

int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};

void solve()
{
    while(n--)
    {
        char tmp[100][100];
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                char goal = ' ';
                bool flag = false;
                if(map[i][j]=='R') goal = 'P';
                else if(map[i][j]=='P') goal = 'S';
                else if(map[i][j]=='S') goal = 'R';
                for(int k=0; k<4; k++)
                {
                    int nextX = i + dx[k];
                    int nextY = j + dy[k];
                    if(nextX>=0 && nextX<r && nextY>=0 && nextY<c && map[nextX][nextY]==goal)
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag)
                {
                    tmp[i][j] = goal;
                }
                else
                {
                    tmp[i][j] = map[i][j];
                }
            }
        }
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                map[i][j] = tmp[i][j];
            }
        }
    }
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<map[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    cin>>t;
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}

void input()
{
    cin>>r>>c>>n;
    cin.ignore();
    string line;
    for(int i=0; i<r; i++)
    {
        cin>>line;
        for(int j=0; j<c; j++)
        {
            map[i][j] = line[j];
        }
    }
}

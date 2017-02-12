#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> node;

int m, s;
short h[1010][1010];
short v[1010][1010];
vector<node> vec;

void solve()
{
    node a, b;
    int l, w;
    int ans = 0;
    for(int i=0; i<vec.size(); i++)
    {
        a = vec[i];
        for(int j=i+1; j<vec.size(); j++)
        {
            b = vec[j];
            if(a.first==b.first || a.second==b.second) continue;
            l = max(a.first, b.first) - min(a.first, b.first);
            w = max(a.second, b.second) - min(a.second, b.second);
            if(h[a.first][b.second] && v[a.first][b.second] && h[b.first][a.second] && v[b.first][a.second])
            {
                if(v[a.first][b.second]==v[a.first][a.second] && h[a.first][b.second]==h[b.first][b.second])
                {
                    if(v[b.first][a.second]==v[b.first][b.second] && h[b.first][a.second]==h[a.first][a.second])
                    {
                        ans++;
                    }
                }
            }
        }
    }
    printf("%d\n", ans/2);
}

int main()
{
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &s);
        int a, b, c, d;
        vec.clear();
        for(int i=0; i<=1000; i++)
        {
            for(int j=0; j<=1000; j++)
            {
                h[i][j] = 0;
                v[i][j] = 0;
            }
        }
        
        for(int i=1; i<=s; i++)
        {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if(a==c)
            {
                for(int j=min(b, d); j<=max(b, d); j++)
                {
                    v[a][j] = i;
                    if(h[a][j]) vec.push_back(node(a, j));
                }
            }
            else
            {
                for(int j=min(a, c); j<=max(a, c); j++)
                {
                    h[j][b] = i;
                    if(v[j][b]) vec.push_back(node(j, b));
                }
            }
        }
        solve();
    }
    return 0;
}

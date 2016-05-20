#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge
{
    int from, to;
    double cost, com;
};

int n, m, s;
double v;
edge e[210];
double dist[110];

int main()
{
    scanf("%d%d%d%lf", &n, &m, &s, &v);
    int cnt = 0;
    int a, b;
    double r1, c1, r2, c2;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%lf%lf%lf%lf", &a, &b, &r1, &c1, &r2, &c2);
        e[cnt++] = {a, b, r1, c1};
        e[cnt++] = {b, a, r2, c2};
    }
    
    bool is_poss = false;
    memset(dist, 0.0, sizeof(dist));
    dist[s] = v;
    for(int i=0; i<=cnt; i++)
    {
        bool flag = false;
        for(int j=0; j<cnt; j++)
        {
            edge current = e[j];
            double next_dist = (dist[current.from] - current.com) * current.cost;
            if(next_dist<=0) continue;
            if(next_dist>dist[current.to])
            {
                if(i==cnt)
                {
                    flag = true;
                    break;
                }
                dist[current.to] = next_dist;
            }
            
        }
        if(flag)
        {
            is_poss = true;
            break;
        }
    }
    
    if(is_poss) printf("YES\n");
    else printf("NO\n");
    return 0;
}

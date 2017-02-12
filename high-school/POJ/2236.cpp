#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int N, D;
int x[1010];
int y[1010];
bool fixe[1010];
int parent[1010];
int ran[1010];
bool dist[1010][1010];

void pre_cal()
{
    int x1, y1, x2, y2;
    for(int i=1; i<=N; i++)
    {
        x1 = x[i];
        y1 = y[i];
        for(int j=1; j<i; j++)
        {
            x2 = x[j];
            y2 = y[j];
            dist[i][j] = dist[j][i] = (sqrt(pow(x2*1.0-x1*1.0, 2)+pow(y2*1.0-y1*1.0, 2))) <=D*1.0 ;
        }
    }
}

bool dist_of_two(int a, int b)
{
    return dist[a][b];
}

int find_root(int a)
{
    int tmp = a;
    while(parent[a]!=a)
    {
        a = parent[a];
    }
    
    while(parent[tmp]!=tmp)
    {
        int tmp2 = parent[tmp];
        parent[tmp] = a;
        tmp = tmp2;
    }
    
    return a;
}

void merge(int a, int b)
{
    a = find_root(a);
    b = find_root(b);
    if(a==b) return;
    
    if(ran[a] > ran[b])
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
        if(ran[a]==ran[b])
        {
            ran[b]++;
        }
    }
}

int main()
{
    scanf("%d%d\n", &N, &D);
    for(int i=1; i<=N; i++)
    {
        scanf("%d%d\n", &x[i], &y[i]);
        ran[i] = 1;
        parent[i] = i;
    }
    pre_cal();
    char ope = ' ';
    int a = -1, b = -1;
    while(cin>>ope)
    {
        if(ope=='S')
        {
            scanf("%d %d", &a, &b);
            a = find_root(a);
            b = find_root(b);
            if(!fixe[a] || !fixe[b])
            {
                printf("FAIL\n");
            }
            else if(dist_of_two(a,b))
            {
                printf("SUCCESS\n");
            }
            else if(parent[a]==parent[b])
            {
                printf("SUCCESS\n");
            }
            else
            {
                printf("FAIL\n");
            }
        }
        else
        {
            scanf("%d", &a);
            fixe[a] = true;
            for(int i=1; i<=N; i++)
            {
                if(!fixe[i] || i==a) continue;
                if(dist_of_two(a, i))
                {
                    merge(a, i);
                }
            }
        }
        scanf("\n");
    }
    return 0;
}

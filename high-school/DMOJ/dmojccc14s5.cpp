//12 out of 15, didn't get full mark
#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int e1, e2, length;
}e[3000000];

int n, cnt;
int x[2010];
int y[2010];
int dist[2010];
int a[2010];

bool cmp(edge a, edge b)
{
    return a.length<b.length;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    cnt = 0;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            e[cnt++] = {i,j,(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])};
        }
    }
    sort(e, e+cnt, cmp);
    for(int i=0; i<cnt; i++)
    {
        int e1 = e[i].e1;
        int e2 = e[i].e2;
        int length = e[i].length;
        int tmp = a[e2];
        if(length>dist[e1])
        {
            if(e1!=0)  a[e2] = max(a[e2], a[e1]+1);
        }
        int tmp2 = a[e1];
        if(length>dist[e2])
        {
            if(e2!=0) a[e1] = max(a[e1], tmp+1);
        }
        if(a[e2]!=tmp) dist[e2] = length;
        if(a[e1]!=tmp2) dist[e1] = length;
    }
    printf("%d\n", a[0]+1);
    return 0;
}

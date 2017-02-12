#include <cstdio>

using namespace std;

int m, n;
int arr[50010];
int rank[50010];

void unite(int a, int b)
{
    if(rank[a]>rank[b])
    {
        arr[b] = a;
    }
    else
    {
        arr[a] = b;
        if(rank[a]==rank[b])
        {
            rank[b]++;
        }
    }
}

int find_root(int a)
{
    int tmp = a;
    while(arr[a]!=-1)
    {
        a = arr[a];
    }
    
    while(arr[tmp]!=-1)
    {
        int temp = arr[tmp];
        arr[tmp] = a;
        tmp = temp;
    }
    
    return a;
}

int main()
{
    int cnt = 1;
    while(scanf("%d %d", &n, &m), m || n)
    {
        for(int i=1; i<=n; i++)
        {
            rank[i] = 1;
            arr[i] = -1;
        }
        int a, b;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &a, &b);
            a = find_root(a);
            b = find_root(b);
            if(a!=b)
            {
                unite(a, b);
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            if(arr[i]==-1) ans++;
        }
        printf("Case %d: %d\n", cnt++, ans);
    }
    return 0;
}

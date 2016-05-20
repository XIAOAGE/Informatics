#include <cstdio>
#include <iostream>

using namespace std;

int n, m;

int main()
{
    while(scanf("%d%d", &n, &m)!=EOF && n!=-1 && m!=-1)
    {
        int p = 1;
        while((p-1)*p/2<m) p++;
        int tmp  = (p-1)*p/2;
        for(int i=1; i<=n-p; i++) printf("%d ", i);
        printf("%d ", n-(tmp-m));
        for(int j=n; j>n-p; j--) if(j!=n-(tmp-m))printf("%d ", j);
        printf("\n");
    }
    return 0;
}

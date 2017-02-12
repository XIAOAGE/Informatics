#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[10010];
int n, k;

bool check(int number)
{
    int cnt = 0;

    for(int i=0; i<n; i++)
    {
        cnt += a[i]/number;
        if(cnt>=k) return true;
    }
    return false;
}

int main()
{
    while(scanf("%d%d", &n, &k)!=EOF)
    {
        double tmp;
        int lb, ub = -1;
        for(int i=0; i<n; i++)
        {
            scanf("%lf", &tmp);
            a[i] = tmp*100;
            ub = max(a[i], ub);
        }

        lb = 1;
        int res = 0;
        while(ub>=lb)
        {
            int m =(ub+lb)/2;
            if(check(m))
            {
                lb = m+1;
                res = max(res, m);
            }
            else
            {
                ub = m-1;
            }
        }
        printf("%.2f\n", res/100.0);
    }
    return 0;
}

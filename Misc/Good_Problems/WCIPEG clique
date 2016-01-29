#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> p;

int n, m;
bool g[35][35];
int a[1<<16];

int main()
{
    scanf("%d%d", &n, &m);
    int tmp1, tmp2;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d", &tmp1, &tmp2);
        tmp1--;
        tmp2--;
        g[tmp1][tmp2] = true;
        g[tmp2][tmp1] = true;
    }

    int lb = n/2;
    int rb = n-lb;

    int ans = 0;
    //left side
    for(int i=0; i<(1<<lb); i++)
    {
        bool flag = true;
        int tmp = 0;
        for(int j=0; j<lb && flag; j++)
        {
            if(i>>j & 1)
            {
                tmp++;
                for(int k=j+1; k<lb; k++)
                {
                    if((i>>k & 1) && !g[j][k])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag)
        {
            ans = max(ans, tmp);
            a[i] = tmp;
        }
        else
        {
            for(int j=0; j<lb; j++)
            {
                if(i>>j & 1)
                {
                    a[i] = max(a[i], a[i-(1<<j)]);
                }
            }
        }
    }
    //right side
    for(int i=0; i<(1<<rb); i++)
    {
        bool flag =true;
        int tmp = 0;
        for(int j=0; j<rb && flag; j++)
        {
            if(i>>j & 1)
            {
                tmp++;
                for(int k=j+1; k<rb; k++)
                {
                    if((i>>k & 1) && !g[j+lb][k+lb])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag)
        {
            ans = max(ans, tmp);
            int val = (1<<lb) - 1;
            for(int j=0; j<lb; j++)
            {
                bool flag2 = true;
                for(int k=0; k<rb; k++)
                {
                    if((i>>k & 1) && !g[j][k+lb])
                    {
                        flag2 = false;
                        break;
                    }
                }
                if(flag2) continue;
                val -= (1<<j);
            }
            ans = max(ans, a[val]+tmp);
        }
    }

    printf("%d\n", ans);
    return 0;
}

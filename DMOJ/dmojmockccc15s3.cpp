#include <bits/stdc++.h>

using namespace std;

int n;
int x[11], y[11];
int num[11];

int cmp(int num)
{
    if(num==0) return 0;
    else if(num>0) return 1;
    else return -1;
}

int det(int p1, int p2, int p3)
{
    int x1 = x[p1];
    int y1 = y[p1];
    int x2 = x[p2];
    int y2 = y[p2];
    int x3 = x[p3];
    int y3 = y[p3];
    return cmp((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
}

bool is_intercept(int p1, int p2, int p3, int p4)
{
    if(p2==p3) return det(p3,p1,p4)==0;
    else if(p4==p1) return det(p1,p2,p3)==0;
    return det(p3, p4, p1)*det(p3, p4, p2) <=0 && det(p1,p2,p3)*det(p1,p2,p4)<=0;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)  scanf("%d%d", &x[i], &y[i]);
    for(int i=0; i<n; i++) num[i] = i;
    int ans = 0;
    do
    {
        bool flag = true;
        for(int i=0; flag && i<n; i++)
        {
            int d1 = num[i];
            int d2 = i+1;
            if(d2==n) d2 = 0;
            d2 = num[d2];
            for(int j=i+1; flag && j<n; j++)
            {
                int d3 = num[j];
                int d4 = j+1;
                if(d4==n) d4 = 0;
                d4 = num[d4];
                if(is_intercept(d1,d2,d3,d4))
                {
                    flag = false;
                }
            }
        }
        if(flag) ans++;
    }while(next_permutation(num, num+n));
    cout<<ans<<endl;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

int t, n;
p u[5010];
int v[5010];
int a[5010];
int dp[5010];

void solve()
{
    sort(u, u+n);
    for(int i=0; i<n; i++)
    {
        a[i] = v[u[i].second];
    }

    dp[0] = 1;
    int ans = 0;
    for(int i=1; i<n; i++)
    {
        dp[i] = 1;
        for(int j=i-1; j>=0; j--)
        {
            if(a[i]<a[j])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
}

int main()
{
    scanf("%d", &t);
    int a, b;
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &a, &b);
            u[i] = p(a, i);
            v[i] = b;
        }
        solve();
    }
    return 0;
}

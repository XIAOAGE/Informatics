#include <bits/stdc++.h>

#define ll long long
#define INF 1000000010

using namespace std;

typedef pair<int, int> node;

int n;
node a[100010];
node b[100010];
ll dp[100010][4];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int c,d;
        scanf("%d%d", &c, &d);
        a[i] = node(c, d);
        b[i] = node(d, c);
    }
    sort(a, a+n);
    sort(b, b+n);
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        node cur = a[i];
        int l = lower_bound(a, a+n, node(cur.first, -INF))-a;
        int m = lower_bound(a, a+n, node(cur.first, cur.second))-a;
        int r = upper_bound(a, a+n, node(cur.first, INF))-a;
        dp[i][0] = r-m-1;
        dp[i][1] = m-l;
        l = lower_bound(b, b+n, node(cur.second, -INF))-b;
        m = lower_bound(b, b+n, node(cur.second, cur.first))-b;
        r = upper_bound(b, b+n, node(cur.second, INF))-b;
        dp[i][2] = m-l;
        dp[i][3] = r-m-1;
        ans += (dp[i][0]*dp[i][1]*dp[i][2]*dp[i][3]);
    }
    printf("%lld", ans*2);
    return 0;
}

/*
12
-3 6
1 6
-1 4
-3 2
1 2
4 2
-4 -3
-3 -3
1 -3
-1 -4
1 -4
-3 -6
*/

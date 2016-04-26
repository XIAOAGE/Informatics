#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, r;
ll e, c1, v1, ca, cb, va, vb, cm, vm;
ll dp[2010];
vector<int> g[2010];

int main()
{
    scanf("%d%d", &n, &r);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &e,&c1,&v1,&ca,&cb,&cm,&va,&vb,&vm);
        ll c = c1, v = v1, cnt = 1;
        while(cnt++<=e)
        {
            if(c<=r) g[(int)c].push_back((int)v);
            c = (c*ca+cb)%cm;
            v = (v*va+vb)%vm;
        }
    }
    ll ans = 0;
    for(int i=1; i<=r; i++) sort(g[i].begin(), g[i].end());

    for(int i=1; i<=r; i++)
        for(int j=0; j<g[i].size() && (j+1)*i<=r; j++)
            for(int k=r; k>=i; k--)
                dp[k] = max(dp[k], dp[k-i]+g[i][g[i].size()-j-1]);

    for(int i=1; i<=r; i++) ans = max(ans, dp[i]);
    for(int i=0; i<g[0].size(); i++) ans += g[0][i];
    printf("%lld\n", ans);
    return 0;
}

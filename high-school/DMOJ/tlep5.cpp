#include <cstdio>
#include <iostream>

#define mod 1000000007
#define ll long long

using namespace std;

ll n, m;
ll a[2010];
ll b[2010];

ll mod_pow(ll x, ll p)
{
    ll ret = 1;
    while(p>0)
    {
        if(p&1){ret = ret * x % mod;}
        x =  x * x % mod;
        p >>= 1;
    }
    return ret;
}

int main()
{
    scanf("%lld", &n);
    for(int i=0; i<n; i++) scanf("%lld", &a[i]);
    scanf("%lld", &m);
    m--;
    b[0] = 1;
    for(int i=1; i<n; i++) b[i] = (((m+i)*b[i-1])%mod * mod_pow(i, mod-2)) % mod;
    for(int i=0; i<n; i++)
    {
        ll ans = 0;
        for(int j=i,k=0; j>=0; j--,k++) ans = (ans+(b[j]*a[k])%mod) % mod;
        printf("%lld ", ans);
    }
    printf("\n");
    return 0;
}

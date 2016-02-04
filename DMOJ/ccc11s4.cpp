#include <bits/stdc++.h>

using namespace std;

int a[10];
int b[10];
int c[10];

int main()
{
    for(int i=0; i<8; i++) cin>>a[i];
    for(int i=0; i<8; i++) cin>>b[i];
    for(int i=0; i<8; i++) c[i] = b[i];
    for(int i=0; i<8; i++)
    {
        b[i] = max(b[i]-a[i], 0);
        a[i] = max(a[i]-c[i], 0);
    }

    for(int i=7; i>=0; i--)
    {
        int j = i+1;
        if(i==3) j=6;
        for(; j<8; j++)
        {
            if(i==2 && j==4) continue;
            if(i==2 && j==5) continue;
            if(j%2==0 && i%2==1) continue;
            int tmp = b[j];
            b[j] = max(b[j]-a[i], 0);
            a[i] = max(a[i]-tmp, 0);
        }
    }
    int ans = 0;
    for(int i=0; i<8; i++)
    {
        ans += c[i]-b[i];
    }
    cout<<ans<<endl;
    return 0;
}

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n, p;

int main()
{
    cin>>n>>p;
    int ans = 0;
    int a;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a);
        ans += pow(a, p)>0 ? pow(a, p) : 0;
    }
    cout<<ans<<endl;
    return 0;
}

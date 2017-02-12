#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[110];
int b[110];

int abs(int a)
{
    return a>=0 ? a : -1*a;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    b[0] = a[0];
    b[n-1] = a[n-1];
    int ans = 0;
    for(int i=1; i<n-1; i++)
    {
        if(b[i-1]>a[i] && a[i+1]>a[i])
        {
            b[i] = min(b[i-1], a[i+1]);
        }
        else if(b[i-1]<a[i] && a[i+1]<a[i])
        {
            b[i] = max(b[i-1], a[i+1]);
        }
        else
        {
            b[i] = a[i];
        }
    }
    
    for(int i=0; i<n; i++)
        ans += abs(a[i] - b[i]);
    for(int i=0; i<n-1; i++)
        ans += abs(b[i] - b[i+1]);
    cout<<ans<<endl;
    return 0;
}

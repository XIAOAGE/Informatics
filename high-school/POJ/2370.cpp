#include <iostream>
#include <algorithm>

using namespace std;

int K;
int arr[110];

int main()
{
    cin>>K;
    for(int i=0; i<K; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+K);
    int ans = 0;
    for(int i=0; i<K/2+1; i++)
    {
        ans += arr[i]/2+1;
    }
    cout<<ans<<endl;
    return 0;
}

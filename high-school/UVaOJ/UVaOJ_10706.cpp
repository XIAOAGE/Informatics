#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

long long sum[31269];
long long arr[31269];
long long N, number;

long long bianry_search(long long num)
{
    int left = 1, right = 31268;
    while(right>=left)
    {
        int mid = (right+left)/2;
        if(sum[mid]>=num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right+1;
}

long long bianry_search2(long long num)
{
    int left = 1, right = 31268;
    while(right>=left)
    {
        int mid = (right+left)/2;
        if(arr[mid]>=num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right+1;
}


void solve()
{
    long long index = bianry_search(number);
    if(index>1)
    {
        number = number - sum[index-1];
    }
    index = bianry_search2(number);
    if(index>1)
    {
        number = number - arr[index-1];
    }
    string str = to_string(index);
    cout<<str[number-1]<<endl;
}

void pre_solve()
{
    arr[1] = sum[1] = 1;
    for(int i=2; i<31269; i++)
    {
        arr[i] = arr[i-1] + log10(i)+1;
        sum[i] = sum[i-1] + arr[i];
    }
}

int main()
{
    pre_solve();
    cin>>N;
    while(N--)
    {
        cin>>number;
        solve();
    }
    return 0;
}
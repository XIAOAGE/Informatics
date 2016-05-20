#include <iostream>

using namespace std;

int n;
int number;
int dp[50][2];

void solve()
{
    dp[1][0] = dp[1][1] = 1;
    for(int i=2; i<=number; i++)
    {
        dp[i][1] = dp[i-1][0];
        dp[i][0] = dp[i-1][1] + dp[i-1][0];
    }
    
    cout<<dp[number][1] + dp[number][0]<<endl;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"Scenario #"<<i<<":"<<endl;
        cin>>number;
        solve();
        cout<<endl;
    }
    return 0;
}

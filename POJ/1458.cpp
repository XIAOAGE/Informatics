#include <iostream>
#include <algorithm>

using namespace std;

string a, b;
int dp[3000][3000];

int main()
{
    string line;
    while(cin>>a>>b)
    {
        for(int i=1; i<=a.length(); i++)
        {
            for(int j=1; j<=b.length(); j++)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(a[i-1]==b[j-1])
                {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
        cout<<dp[a.length()][b.length()]<<endl;
    }
    return 0;
}

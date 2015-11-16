#include <bits/stdc++.h>

using namespace std;

int dp[2010][2010];
int ans;
int n;
bool g[2010][2010];

int main()
{
    scanf("%d", &n);
    getchar();
    char tmp;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%c", &tmp);
            cout<<tmp;
            if(tmp=='#') g[i][j] = true;
            else g[i][j] = false;
        }
        cout<<endl;
        getchar();
    }
    ans = 0;
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<n; j++)
        {
            if(!g[i][j]) continue;
            if(i+1>=n || j-1<0 || j+1>=n) {dp[i][j] = 1; ans++;}
            else
            {
                int lv = min(dp[i+1][j-1], min(dp[i+1][j+1], dp[i+1][j]))+1;
                dp[i][j] = lv;
                ans = ans+lv;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

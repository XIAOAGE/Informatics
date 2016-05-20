#include <cstdio>

using namespace std;

int n;
int dp[50][8];
int ans[31];

bool check(int number)
{
    bool zero = false;
    for(int i=0; i<3; i++)
    {
        if(number>>i & 1)
        {
            if(zero) return false;
            continue;
        }
        else
        {
            zero = !zero;
        }
    }
    return !zero;
}

bool check_row(int a, int b)
{
    bool zero = false;
    for(int i=0; i<3; i++)
    {
        if(a>>i & 1)
        {
            if(b>>i&1) return false;
        }
        else if(!(b>>i & 1))
        {
            zero = !zero;
        }
        else if(b>>i & 1)
        {
            if(zero) return false;
        }
    }
    return !zero;
}

bool check_last(int number)
{
    for(int i=0; i<3; i++) if(number>>i & 1) return false;
    return true;
}

int main()
{
    ans[0] = 1;
    for(int i=0; i<8; i++)
    {
        dp[0][i] = 0;
        if(check(i))
        {
            dp[0][i] = 1;
        }
        if(check_last(i))ans[1] += dp[0][i];
    }

    for(int i=1; i<30; i++)
    {
        for(int j=0; j<8; j++)
        {
            for(int k=0; k<8; k++)
            {
                if(check_row(k, j))
                {
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        ans[i+1] = dp[i][0];
    }

    while(scanf("%d", &n), n!=-1)
    {
        printf("%d\n", ans[n]);
    }
    return 0;
}

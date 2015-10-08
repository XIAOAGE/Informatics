/*
 题意：类似开关问题，给一个n*n的一个表格，每个格子可以放1或者0，在放1时一定要保证上下左右没有格子也放了1
 问一共有多少中放法
 思路：二进制，主要是要用DP，i为当前行，j为状态，dp[i][j] = sum(dp[i-1][k]) (k is the state that i&k==0)
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
int ans;

bool check(int number)
{
    int flag = 0;
    while(number)
    {
        if((number & 1) && flag)
        {
            return false;
        }
        else if(number & 1)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        number/=2;
    }
    return true;
}

vector<int> vec;

long long sum[8][256];

void solve()
{
    cin>>n;
    for(int i=0; i<pow(2,n); i++)
    {
        if(check(i)) vec.push_back(i);
    }
    
    long long ans = 0;
    
    for(int i=0; i<vec.size(); i++)
    {
        if(i!=n-1)
        {
            sum[0][i] = 1;
        }
        else
        {
            ans++;
        }
    }
    
    if(n!=1)
    {
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<vec.size(); j++)
            {
                for(int k=0; k<vec.size(); k++)
                {
                    if(i!=n-1)
                    {
                        if((j&k)==0)
                        {
                            sum[i][j] += sum[i-1][k];
                        }
                    }
                    else
                    {
                        ans += sum[i-1][k];
                    }
                }
            }
        }
    }
    
    cout<<ans<<endl;
    
}

int main()
{
    solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int c, n;
int d[15];
int number[15];
int dp[100010];

void complete_knapsack(int row)
{
     for(int i=d[row]; i<=c; i++) dp[i] = max(dp[i], dp[i-d[row]]+d[row]);
}

void zero_one(int val)
{
     for(int i=c; i>=val; i--) dp[i] = max(dp[i], dp[i-val]+val);
}

void multi_knapsack(int row)
{
     if(number[row]*d[row]>=c) complete_knapsack(row);
     else
     {
         int k = 1;
         int m = number[row];
         while(k<m)
         {
             zero_one(d[row]*k);
             m-=k;
             k<<=1;
         }
         zero_one(m*d[row]);
     }
}

void solve()
{
     for(int i=0; i<n; i++)  multi_knapsack(i);
     cout<<dp[c]<<endl;
}

int main()
{
     while(cin>>c)
     {
         cin>>n;
         for(int i=0; i<n; i++)  cin>>number[i]>>d[i];
         for(int i=0; i<=c; i++) dp[i] = 0;
         solve();
     }
     return 0;
}
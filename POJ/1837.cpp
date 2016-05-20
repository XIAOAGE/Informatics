#include <iostream>

using namespace std;

const int MAX = 20;
int C, G;
int dist[MAX];
int weight[MAX];
int dp[MAX][16000];

void solve()
{
    for(int j=0; j<C; j++)
    {
        dp[0][weight[0]*dist[j]+7500]++;
    }
    
    for(int i=1; i<G; i++)
    {
        for(int j=0; j<C; j++)
        {
            for(int k=0; k<16000; k++)
            {
                if(dp[i-1][k-weight[i]*dist[j]])
                {
                    dp[i][k] += dp[i-1][k-weight[i]*dist[j]];
                }
            }
        }
    }
    
    cout<<dp[G-1][7500]<<endl;
    
}

int main()
{
    cin>>C>>G;
    for(int i=0; i<C; i++)
    {
        cin>>dist[i];
    }
    
    for(int i=0; i<G; i++)
    {
        cin>>weight[i];
    }

    solve();
    return 0;
}

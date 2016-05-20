#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define MAX_V 300 + 16
int d[MAX_V][MAX_V];   //  d[u][v]表示边e=(u,v)的权值，不存在的时候等于无穷大或者d[i][i] = 0
int V;                 //  顶点数
int x[MAX_V];
 
void warshall_floyd()
{
    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int M;
    cin >> V >> M;
    memset(d, 0x3f, sizeof(d));
    for (int i = 0; i < V; ++i)
    {
        d[i][i] = 0;
    }
    while (M--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> x[i];
            --x[i];
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                d[x[i]][x[j]] = d[x[j]][x[i]] = 1;
            }
        }
    }
    warshall_floyd();
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < V; ++i)
    {
        int sum = 0;
        for (int j = 0; j < V; ++j)
        {
            sum += d[i][j];
        }
        ans = min(ans, sum);
    }
    cout << 100 * ans / (V - 1) << endl;
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif
    return 0;
}

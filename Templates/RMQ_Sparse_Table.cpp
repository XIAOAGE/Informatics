/*
    Make Table: O(NlogN)
    Query: (1)
    This is the solution to POJ 3264, which is totally a RMQ problem.

    st_ma is for maximum number; st_min is for minimum number;
    st[i][j] indicate the range that starts from i and have length of
    j. (include i)

    Notice the array starts from 0
*/

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int N, Q;
int arr[50010];
int st_ma[50010][20];
int st_mi[50010][20];

void build_st()
{
    for(int i=0; i<N; i++)
    {
        st_ma[i][0] = arr[i];
        st_mi[i][0] = arr[i];
    }
    for(int j=1; (1<<j)<=N; j++)
    {
        for(int i=0; i+(1<<j)<=N; i++)
        {
            st_ma[i][j] = max(st_ma[i][j-1], st_ma[i+(1<<(j-1))][j-1]);
            st_mi[i][j] = min(st_mi[i][j-1], st_mi[i+(1<<(j-1))][j-1]);
        }
    }
}

int mi_query(int i, int j)
{
    int k = log(double(j-i+1))/log(2.0);
    return min(st_mi[i][k], st_mi[j-(1<<k)+1][k]);
}

int ma_query(int i, int j)
{
    int k = log(double(j-i+1))/log(2.0);
    return max(st_ma[i][k], st_ma[j-(1<<k)+1][k]);
}

int main()
{
    scanf("%d%d", &N, &Q);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    build_st();
    int a, b;
    while(Q--)
    {
        scanf("%d%d", &a, &b);
        a--, b--;
        printf("%d\n", ma_query(a, b)-mi_query(a, b));
    }
    return 0;
}

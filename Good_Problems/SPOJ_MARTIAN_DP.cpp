/*
 * 题意描述：
 * 就是有两种元素，每个格子中的两种元素的两不同，一种元素必须要运到北部，另一种必须要运到西部。
 * 求元素采集总量的最大值。
 *
 * 思路：
 * 仔细观察后发现，对于任意一个cell，要么当前一列全部向上，要么当前一行全部向左（为了达到最大化，不能有任何一个cell的元素浪费）
 *
 */
#include <stdio.h>
#include <algorithm>

using namespace std;

int R, C;
const int MAX_N = 510;
int Bo[MAX_N][MAX_N];
int Ye[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main()
{
    while(true)
    {
       scanf("%d %d", &R, &C);
       if(!R && !C)
       {
           break;
       }

       for(int i=0; i<R; i++)
       {
           scanf("%d", &Ye[i][0]);
           for(int j=1; j<C; j++)
           {
               int temp = -1;
               scanf("%d", &temp);
               Ye[i][j] = temp + Ye[i][j-1];
           }
       }

       for(int j=0; j<C; j++)
       {
           scanf("%d", &Bo[0][j]);
       }

       for(int i=1; i<R; i++)
       {
           for(int j=0; j<C; j++)
           {
               int temp = -1;
               scanf("%d", &temp);
               Bo[i][j] = temp + Bo[i-1][j];
           }
       }

       dp[0][0] = max(Ye[0][0], Bo[0][0]);
       for(int i=1; i<C; i++)
       {
           dp[0][i] = max(Ye[0][i], dp[0][i-1]+Bo[0][i]);
       }

       for(int i=1; i<R; i++)
       {
           dp[i][0] = max(Bo[i][0], dp[i-1][0]+Ye[i][0]);
       }

       for(int i=1; i<R; i++)
       {
           for(int j=1; j<C; j++)
           {
               dp[i][j] = max(dp[i-1][j]+Ye[i][j], dp[i][j-1]+Bo[i][j]);
           }
       }
       printf("%d\n", dp[R-1][C-1]);
    }
    return 0;
}

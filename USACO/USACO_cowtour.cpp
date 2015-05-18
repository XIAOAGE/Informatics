/*
题意：坑爹的题意， 有不同一片片农田， 每一片农田里的所有农场都是联通的。 农田的半径是任意两个农场之间的最大距离值。
     你可以在两个不相通的农田之间连一条边，是的这个半径最小。
思路： 把每一个农场看作是一个单体,然后计算出他在的农田中的一它为一个定点的最长距离。 怎么区分联通？ 就是看这两个农场之间的距离是不是INF，
      如果是我们就可以尝试着连一条边。
*/

/*
ID: qiangbr1
PROG: cowtour
LANG: C++11
*/

#define USACO
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 155, INF = 0x7fffffff;
int N;
int X[MAXN], Y[MAXN];
double point_dis[MAXN][MAXN], dis[MAXN][MAXN], farthest[MAXN];
bool G[MAXN][MAXN];

inline double get_dis(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void floyd(int n)
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main()
{
    #ifdef USACO
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
    #endif;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) scanf("%d%d\n", &X[i], &Y[i]);
    for (int i = 0; i < N; i++, getchar())
        for (int j = 0; j < N; j++)
            G[i][j] = getchar() - '0';

    for (int i = 0; i < N; i++)
        for (int j = 0 ; j < N; j++) {
            if (i == j) {point_dis[i][j] = dis[i][j] = 0; continue;}
            point_dis[i][j] = get_dis(X[i], Y[i], X[j], Y[j]);
            if (G[i][j]) dis[i][j] = point_dis[i][j];
            else dis[i][j] = INF;
        }
    floyd(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (dis[i][j] < INF) farthest[i] = max(farthest[i], dis[i][j]);
    double ans = INF;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) if (dis[i][j] == INF) {
            double nowmax = farthest[i] + point_dis[i][j] + farthest[j];
            if (nowmax >= ans) continue;
            for (int k = 0; k < N; k++) nowmax = max(nowmax, farthest[k]);
            ans = nowmax;
        }
    printf("%.6lf\n", ans);
    fclose(stdin); fclose(stdout);
    return 0;
}

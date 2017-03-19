#include <bits/stdc++.h>

using namespace std;

int n, board[2010];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        board[tmp]++;
    }
    int ans1 = -1, ans2 = 0;
    for(int i=1; i<=2000; i++)
    {
        int lb = i-1, rb = i+1, cnt=board[i]/2;
        while(lb>=1 && rb<=2000) cnt += min(board[lb--], board[rb++]);
        if(ans1<cnt) ans1 = cnt, ans2 = 1;
        else if(ans1==cnt) ans2++;
    }
    for(int i=1; i<2000; i++)
    {
        int lb = i, rb = i+1, cnt = 0;
        while(lb>=1 && rb<=2000) cnt += min(board[lb--], board[rb++]);
        if(ans1<cnt) ans1 = cnt, ans2 = 1;
        else if(ans1==cnt) ans2++;
    }
    printf("%d %d\n", ans1, ans2);
}
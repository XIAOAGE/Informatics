#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
struct bode
{
    int x,y;
} node[5005];
bool vis[5005][5005];
int n,disx,disy,r,c,tmpx,tmpy,max1=0,cnt;
int cmp(const bode &a,const bode &b)
{
    if(a.y==b.y)return a.x<b.x;
    else return a.y<b.y;
}
int main()
{
    scanf("%d%d",&r,&c);
    scanf("%d",&n);
    memset(vis,false,sizeof(vis));
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&node[i].x,&node[i].y);
        vis[node[i].x][node[i].y]=true;
    }
    sort(node,node+n,cmp);
    max1=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            disx=node[j].x-node[i].x;
            disy=node[j].y-node[i].y;
            if(node[i].x-disx>0&&node[i].x-disx<=r&&node[i].y-disy>0&&node[i].y-disy<=c)continue;
            tmpx=node[j].x+disx;
            tmpy=node[j].y+disy;
            cnt=0;
            while(tmpx>0&&tmpx<=r&&tmpy>0&&tmpy<=c)
            {
                if(vis[tmpx][tmpy])cnt++;
                else
                {
                    cnt=0;
                    break;
                }
                tmpx+=disx;
                tmpy+=disy;
            }
            max1=max(max1,cnt);
        }
    }
    if(max1)
        printf("%d\n",max1+2);
    else puts("0");
    return 0;
}

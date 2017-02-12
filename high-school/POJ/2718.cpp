#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int a[12],b[12],n,ans;
bool vis[12];
void solve(int aa)
{
    int len=0;
    int bb=0;
    for(int i=0;i<n;i++)
        if(!vis[i])
            b[len++]=a[i],bb=bb*10+a[i];
    if(b[0]!=0||len==1)
        ans=min(ans,abs(aa-bb));
    while(next_permutation(b,b+len))
    {
        bb=0;
        for(int i=0;i<len;i++)
            bb=bb*10+b[i];
        if(b[0]!=0||len==1)
            ans=min(ans,abs(aa-bb));
    }
}
void dfs(int k,int res)
{
    if(k==n/2)
    {
        solve(res);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(a[i]==0&&k==0&&n>3)
                continue;
            vis[i]=true;
            dfs(k+1,res*10+a[i]);
            vis[i]=false;
        }
    }
}
int main()
{
    int T;
    for(scanf("%d ",&T);T;T--)
    {
        n=0;
        char ch;
        while((ch=getchar())!='\n')
        {
            if(ch==' ')
                continue;
            a[n++]=ch-'0';
        }
        ans=inf;
        memset(vis,false,sizeof(vis));
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}

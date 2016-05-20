#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
map<string,int> MP;
const int inf=0x3f3f3f3f;
int dp[300][300],tot[300],val[300],head[300],nc,n,m;
bool vis[300];
struct Edge
{
    int to,next;
}edge[300*300];
void add(int a,int b)
{
    edge[nc].to=b;edge[nc].next=head[a];head[a]=nc++;
}
void dfs(int now)
{
    vis[now]=true;
    dp[now][0]=0;
    tot[now]=0;
    for(int i=head[now];i!=-1;i=edge[i].next)
    {
        int to=edge[i].to;
        if(!vis[to])
            dfs(to);
        int num=tot[to],all=tot[now]+tot[to];
        tot[now]=all;
        for(int i=all;i>=1;i--)
        {
            for(int j=0;j<=num&&j<=i;j++)
            {
                dp[now][i]=min(dp[now][i],dp[now][i-j]+dp[to][j]);
            }
        }
    }
    dp[now][++tot[now]]=val[now];
}
int main()
{
    char s[100000];
    while(gets(s),strcmp(s,"#")!=0)
    {
        sscanf(s,"%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        memset(vis,false,sizeof(vis));
        memset(val,0,sizeof(val));
        memset(dp,0x3f,sizeof(dp));
        nc=0;MP.clear();
        int num=0;
        for(int i=1,j,k,id;i<=n;i++)
        {
            gets(s);
            char tp[100];
            for(j=0;s[j]!=' ';j++);
            s[j]='\0';
            strcpy(tp,s);
            for(++j,k=0;s[j]!='\0'&&s[j]!=' ';j++)
                k=k*10+s[j]-'0';
            if(MP.find(tp)==MP.end())
                id=MP[tp]=++num;
            else
                id=MP[tp];
            val[id]=k;
            if(s[j]=='\0')
                continue;
            else
            {
                for(k=++j;s[j]!='\0';j++)
                {
                    if(s[j]==' ')
                    {
                        s[j]='\0';
                        strcpy(tp,s+k);
                        if(MP.find(tp)!=MP.end())
                            add(id,MP[tp]);
                        else
                            add(id,MP[tp]=++num);
                        vis[MP[tp]]=true;
                        k=j+1;
                    }
                }
                if(s[k]!=' '&&s[k]!='\0')
                {
                    strcpy(tp,s+k);
                    if(MP.find(tp)!=MP.end())
                        add(id,MP[tp]);
                    else
                        add(id,MP[tp]=++num);
                    vis[MP[tp]]=true;
                }
            }
        }
        val[0]=inf;
        for(int i=1;i<=num;i++)
            if(!vis[i])
                add(0,i);
        memset(vis,false,sizeof(vis));
        dfs(0);
        int ans=inf,len=tot[0];
        for(int i=m;i<len;i++)
            ans=min(ans,dp[0][i]);
        printf("%d\n",ans);
    }
    return 0;
}

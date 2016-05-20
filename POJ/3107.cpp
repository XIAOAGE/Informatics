//树形DP+前向星
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 50005
#define inf ((1<<30)-1)
#define max(a,b) ((a)>(b)?(a):(b))
int n;
int dp[MAX];
int num[MAX];
int edge[MAX<<1];//表示第i条边的终点
int next[MAX<<1];//与第i条边同起点的下一条边的位置
int head[MAX<<1];//以i为起点的第一条边的储存位置
vector<int> out;
void insert(int i,int a,int b)//a起点,b终点
{
    edge[i]=b;
    next[i]=head[a];
    head[a]=i;
}
void dfs(int x,int pre)
{
    int summ=0,k;
    dp[x]=0;
    num[x]=1;
    for(int i=head[x];i!=-1;i=next[i])
    {
        k=edge[i];
        if(k!=pre)
        {
            dfs(k,x);
            summ+=num[k];
            dp[x]=max(dp[x],num[k]);//处理孩子结点的情况
        }
    }
    num[x]=summ+1;
    dp[x]=max(dp[x],n-summ-1);//处理父结点的情况
}
int main()
{
    int a,b;
    for(;~scanf("%d",&n);)
    {
        memset(num,0,sizeof(dp));
        memset(next,-1,sizeof(next));
        memset(head,-1,sizeof(head));
        memset(edge,-1,sizeof(edge));
        for(int i=1;i<=2*(n-1);i+=2)
        {
            scanf("%d%d",&a,&b);
            insert(i,a,b);
            insert(i+1,b,a);
        }
        dfs(1,-1);
        int ans=inf;
        for(int i=1;i<=n;++i)
            if(dp[i]<ans)
            {
                ans=dp[i];
                out.clear();
                out.push_back(i);
            }
            else if(dp[i]==ans)
                out.push_back(i);
        sort(out.begin(),out.end());
        for(int i=0;i<out.size();++i)
            if(i==0) printf("%d",out[i]);
            else     printf(" %d",out[i]);
        printf("\n");
    }
    return 0;
}

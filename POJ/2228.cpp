#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long ll;
int n,b,a[3900];
ll dp[2][3900][2];
ll max(ll a,ll b){
    return a>b?a:b;
}
int main(){
    int i,j;
    ll ans=0;
    while(scanf("%d %d",&n,&b)==2){
        ans=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,-1,sizeof(dp));
        dp[1][1][1]=0;
        int now=0;
        for(i=2;i<=n;i++){
            for(j=0;j<=n;j++)
                dp[now][j][0]=dp[now][j][1]=-1;
            for(j=0;j<=b && j<=i;j++){
                if(j!=0){
                    if(dp[!now][j-1][0]!=-1)
                        dp[now][j][1]=max(dp[!now][j-1][0],dp[now][j][1]);
                    if(dp[!now][j-1][1]!=-1)
                        dp[now][j][1]=max(dp[!now][j-1][1]+a[i],dp[now][j][1]);
                }
                if(dp[!now][j][0]!=-1)
                    dp[now][j][0]=max(dp[!now][j][0],dp[now][j][0]);
                if(dp[!now][j][1]!=-1)
                    dp[now][j][0]=max(dp[!now][j][1],dp[now][j][0]);
            }
            now=!now;
        }
        ans=max(ans,dp[!now][b][1]+a[1]);
        ans=max(ans,dp[!now][b][0]);
        
        memset(dp,-1,sizeof(dp));
        dp[1][0][0]=0;
        now=0;
        for(i=2;i<=n;i++){
            for(j=0;j<=n;j++)
                dp[now][j][0]=dp[now][j][1]=-1;
            for(j=0;j<=b && j<=i;j++){
                if(j!=0){                                //我这里WA了多次....
                    if(dp[!now][j-1][0]!=-1)
                        dp[now][j][1]=max(dp[!now][j-1][0],dp[now][j][1]);
                    if(dp[!now][j-1][1]!=-1)
                        dp[now][j][1]=max(dp[!now][j-1][1]+a[i],dp[now][j][1]);
                }
                if(dp[!now][j][0]!=-1)
                    dp[now][j][0]=max(dp[!now][j][0],dp[now][j][0]);
                if(dp[!now][j][1]!=-1)
                    dp[now][j][0]=max(dp[!now][j][1],dp[now][j][0]);
            }  
            now=!now;  
        }  
        ans=max(ans,dp[!now][b][1]);  
        ans=max(ans,dp[!now][b][0]);  
        printf("%lld\n",ans);  
    }  
}

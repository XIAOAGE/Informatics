#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = int(3e6)+10;
const int N = maxn;

#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int c0(int *r,int a,int b)
{return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}
int c12(int k,int *r,int a,int b)
{if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
    else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];}
void sort(int *r,int *a,int *b,int n,int m)
{
    int i;
    for(i=0;i<n;i++) wv[i]=r[a[i]];
    for(i=0;i<m;i++) ws[i]=0;
    for(i=0;i<n;i++) ws[wv[i]]++;
    for(i=1;i<m;i++) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--) b[--ws[wv[i]]]=a[i];
    return;
}
void dc3(int *r,int *sa,int n,int m)
{
    int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
    r[n]=r[n+1]=0;
    for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
    sort(r+2,wa,wb,tbc,m);
    sort(r+1,wb,wa,tbc,m);
    sort(r,wa,wb,tbc,m);
    for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++)
        rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
    if(p<tbc) dc3(rn,san,tbc,p);
    else for(i=0;i<tbc;i++) san[rn[i]]=i;
    for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;
    if(n%3==1) wb[ta++]=n-1;
    sort(r,wb,wa,ta,m);
    for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;
    for(i=0,j=0,p=0;i<ta && j<tbc;p++)
        sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(;i<ta;p++) sa[p]=wa[i++];
    for(;j<tbc;p++) sa[p]=wb[j++];
    return;
}

int height[N], rank[N];
void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n; height[rank[i++]] = k )
        for(k?k--:0,j=sa[rank[i]-1]; r[j+k]==r[i+k];k++);
}

int sa[N],r[N], n;
char str[N];

/*
 sa[i] : 表示 排在第i位的后缀 起始下标
 
 rank[i] : 表示后缀 suffix(i)排在第几
 
 height[i] : 表示 sa[i-1] 与 sa[i] 的LCP 值(longest common prefix)
 */

int main(){
    while( scanf("%s", str) != EOF )
    {
        if( strcmp(str,".") == 0 ) break;
        n = strlen(str);
        for(int i = 0; i < n; i++)
            r[i] = str[i];
        r[n] = 0;
        //r数组是为了得到整数，只是为了dc3.
        dc3(r,sa,n+1,128);  //注意区分此处为n+1,因为添加了一个结尾字符用于区别比较
        calheight(r,sa,n);
        
        //下面部分是属于POJ 2406的题解，上面是模板
        int length = 1;
        int ans = 1;
        while(length<n)
        {
            if(!(n%length))
            {
                int ra1 = rank[0];
                int ra2 = rank[length];
                int small = min(ra1, ra2)+1;
                int big = max(ra1, ra2);
                int val = height[small++];
                while(small<=big)
                {
                    val = min(val, height[small]);
                    small++;
                }
                if(n-length == val)
                {
                    ans = n/length;
                    break;
                }
            }
            length++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

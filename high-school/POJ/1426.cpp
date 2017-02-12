#include <stdio.h>
int n,flat;
unsigned long long b;
void DFS(unsigned long long a,int step)
{
    if(flat||step==19)
    {
        return ;
    }
    if(a%n==0)
    {
        printf("%I64u\n",a);
        flat=1;
        return ;
    }
    else
    {
        DFS(a*10,step+1);
        DFS(a*10+1,step+1);
    }
    return ;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        flat=0;
        DFS(1,0);
    }
    return 0;
}

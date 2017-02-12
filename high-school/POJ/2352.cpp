#include<stdio.h>
#include<string.h>
#define n 32001 //n=32000时WA了N多次... 
int c[n+5], total[n+5];
int Lowbit(int t)  
{
    return t&(t^(t-1)); 
}
int Sum(int end)   
{
    int sum = 0;
    while(end > 0)
    {
        sum += c[end];
        end -= Lowbit(end);
    }
    return sum;
}
void add(int li, int val) 
{
    while(li<=n)
    {
        c[li] += val;
        li += Lowbit(li);
    }
} 
int main()
{
    int i, j, x, y, nn;
    scanf("%d", &nn); 
    memset(c, 0, sizeof(c)); 
    memset(total, 0, sizeof(total)); 
    for(i=1; i<=nn; i++)
    {
        scanf("%d%d", &x, &y);  //由于坐标x可能为0，因此输入坐标要+1，不然会超时0&(-0)=0; 
        add(x+1, 1);
        total[Sum(x+1)-1]++;
    }
    for(i=0; i<nn; i++)
        printf("%d\n", total[i]);
}

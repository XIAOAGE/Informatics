#include<stdio.h>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef unsigned int i64;
bool iscre[16000002];
int main()
{
    i64 a,c,m,r0,max=0,last;
    scanf("%u%u%u%u",&a,&c,&m,&r0);
    while(1)
    {
        iscre[r0%m] = true;
        r0=(a*r0 + c)%m;
        if(iscre[r0]) break;
    }
    last = -1;
    for(int i=0;i<m;++i)
        if(last != -1 && iscre[i])
        {
            max = MAX(max,i-last);
            last = i;
        }
        else if(iscre[i])
            last = i;
    printf("%u\n",max);
    return 0;
}

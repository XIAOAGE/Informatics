#include <bits/stdc++.h>

using namespace std;

int n, a[1010];

bool is_prime(int num)
{
    for(int i=2; i*i<=num; i++)
        if(num%i==0) return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    int cnt = 0;
    int flag = -1;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i]==1) cnt++;
        if(a[i]!=1 && is_prime(a[i]+1)) flag = a[i];
    }
    if(cnt && flag!=-1 && cnt+1>2)
    {
        printf("%d\n", cnt+1);
        while(cnt--) printf("1 ");
        printf("%d\n", flag);
        return 0;
    }
    else if(cnt>=2)
    {
        printf("%d\n", cnt);
        while(cnt--) printf("1 ");
        printf("\n");
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(is_prime(a[i]+a[j]))
            {
                printf("2\n");
                printf("%d %d\n", a[i], a[j]);
                return 0;
            }
        }
    }
    printf("1\n");
    printf("%d\n", a[1]);
    return 0;
}

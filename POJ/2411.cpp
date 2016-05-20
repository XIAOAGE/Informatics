#include<cstdio>
#include<algorithm>
#include<cmath>
#include <iostream>

using namespace std;

const int MAX_W = 3000;
const int MAX_H = 11;
int w, h;
int tmp1, tmp2;
long long dp[MAX_H][MAX_W];


bool current_last(int current, int last)
{
    int cnt = w-1;
    while(cnt>=0)
    {
        if((current>>cnt&1)==0 && (last>>cnt&1)==0)
        {
            return false;
        }
        if((current>>cnt&1)==1 && (last>>cnt&1)!=0)
        {
            if((current>>cnt&1)==1 && cnt==0)
            {
                return false;
            }
            else if((current>>cnt&1)==1 && (last>>cnt&1)==1 && ((last>>(cnt-1)&1)==0 || (current>>(cnt-1)&1)==0))
            {
                return false;
            }
            cnt--;
        }
        cnt--;
    }
    return true;
}

bool can_be_first(int number)
{
    int cnt = 0;
    while(cnt<w)
    {
        if((number>>cnt & 1)==1)
        {
            cnt++;
            if((number>>cnt & 1)!=1)
            {
                return false;
            }
            else
            {
                cnt++;
            }
        }
        else
        {
            cnt++;
        }
    }
    return true;
}

int main()
{
    while(scanf("%d %d", &tmp1, &tmp2)!=EOF)
    {
        if(tmp1==0 && tmp2==0)
        {
            break;
        }else if((tmp1*tmp2)%2)
        {
            printf("0\n");
            continue;
        }
        w = min(tmp1, tmp2);
        h = max(tmp1, tmp2);
        for(int i=0; i<MAX_H; i++)
        {
            for(int j=0; j<MAX_W; j++)
            {
                dp[i][j] = 0;
            }
        }
        for(int i=0; i<2<<(w-1); i++)
        {
            if(can_be_first(i))
            {
                dp[0][i] = 1;
            }
        }
        for(int i=1; i<h; i++)
        {
            for(int j=0; j<2<<(w-1); j++)
            {
                for(int k=0; k<2<<(w-1); k++)
                {
                    if(current_last(j,k))
                    {
                        dp[i][j] += dp[i-1][k];
                    }
                }
            }
        }
        int fuck_you_Cpp = 2<<(w-1);
        printf("%lld\n",dp[h-1][fuck_you_Cpp-1]);
    }
    return 0;
}


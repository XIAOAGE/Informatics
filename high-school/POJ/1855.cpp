#include <iostream>
#include <algorithm>

using namespace std;

int n, t;
int coin[50];
int height[10];

void input();

int big;
int small;

int gcd(int a, int b)
{
    if(b==0)return a;
    return gcd(b, a%b);
}

int deal_number(int a, int b, int c, int d)
{
    int cd = gcd(c, d);
    int bf = c*d/cd;
    int af = b*bf/gcd(b, bf);
    return a*af/gcd(a, af);
}

void find(int goal, int number)
{
    int coef = 1;
    while(number*coef<=goal)
    {
        coef++;
    }
    if(number*(coef-1)==goal)
    {
        big = max(big, number*(coef-1));
        small = min(small, number*(coef-1));
    }
    else
    {
        big = max(big, number*(coef-1));
        small = min(small, number*coef);
    }
}

void solve()
{
    for(int i=0; i<t; i++)
    {
        big = 0;
        small = 2147483647;
        for(int p=0; p<n-3; p++)
        {
            for(int j=p+1; j<n-2; j++)
            {
                for(int k=j+1; k<n-1; k++)
                {
                    for(int t=k+1; t<n; t++)
                    {
                        find(height[i],deal_number(coin[p], coin[j], coin[k], coin[t]));
                    }
                }
            }
        }
        cout<<big<<" "<<small<<endl;
    }
}

int main()
{
    while(cin>>n>>t, n && t)
    {
        input();
        solve();
    }
    return 0;
}

void input()
{
    for(int i=0; i<n; i++)
    {
        cin>>coin[i];
    }
    for(int i=0; i<t; i++)
    {
        cin>>height[i];
    }
}

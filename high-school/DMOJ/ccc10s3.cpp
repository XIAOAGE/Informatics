#include <bits/stdc++.h>

using namespace std;

int h, k;
int a[1010];

bool check_forward(int len)
{
    stack<int> sta;
    for(int i=h-1; i>=1; i--) sta.push(a[i]);
    int b = a[0]+2*len;
    int cnt = 1;
    while(!sta.empty())
    {
        while(!sta.empty() && sta.top()<=b) sta.pop();
        if(!sta.empty())
        {
            b = sta.top()+2*len;
            sta.pop();
            cnt++;
        }
    }
    return cnt<=k;
}

bool check_backward(int len)
{
    stack<int> sta;
    for(int i=1; i<h; i++) sta.push(a[i]);
    int b = 1000000-(2*len-a[0]);
    int cnt = 1;
    while(!sta.empty())
    {
        while(!sta.empty() && sta.top()>=b) sta.pop();
        if(!sta.empty())
        {
            b = sta.top()-2*len;
            sta.pop();
            cnt++;
        }
    }
    return cnt<=k;
}

int main()
{
    scanf("%d", &h);
    for(int i=0; i<h; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a+h);
    scanf("%d", &k);
    int l = 0, r = 1000000;
    while(r>=l)
    {
        int m = (l+r)/2;
        if(check_forward(m) || check_backward(m))   r = m-1;
        else l = m+1;
    }
    printf("%d\n", l);
    return 0;
}

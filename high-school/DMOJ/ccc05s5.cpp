/*
dont forget divide and conquer!!!!!!!!!!!!!!! when dealing with linear.
*/
#include <bits/stdc++.h>

using namespace std;

int t;
int a[100010];
long long ans;

void merge_sort(int l, int r)
{
    if(l==r) return;
    else
    {
        int b[100010];
        int m = (l+r)/2;
        merge_sort(l, m);
        merge_sort(m+1, r);
        int s = l, e = m+1;
        int cnt = l;
        while(s<=m && e<=r)
        {
            if(a[s]<=a[e])
            {
                b[cnt++] = a[s];
                s++;
            }
            else
            {
                b[cnt++] = a[e];
                ans = ans + m-s+1;
                e++;
            }
        }
        while(s<=m) b[cnt++] = a[s++];
        while(e<=r) b[cnt++] = a[e++];
        for(int i=l; i<=r; i++) a[i] = b[i];
    }
}

int main()
{
    scanf("%d", &t);
    for(int i=0; i<t; i++) scanf("%d", &a[i]);
    ans = 0;
    merge_sort(0, t-1);
    ans += t;
    printf("%.2lf\n", ans*1.0/t);
    return 0;
}

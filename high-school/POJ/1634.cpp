#include <cstdio>
#include <algorithm>

using namespace std;

struct e
{
    int id, s, h;
};
int n, m, q;
e arr[30010];
int ind[10000000];

bool comp(e a, e b)
{
    return a.s<b.s;
}

int main()
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d", &m, &q);
        int a, b, c;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            arr[i] = {a, b, c};
        }
        sort(arr, arr+m, comp);
        for(int i=0; i<m; i++) ind[arr[i].id] = i;
        int v,ans1, ans2;
        for(int i=0; i<q; i++)
        {
            scanf("%d", &v);
            ans1 = 0, ans2 = 0;
            for(int j=ind[v]-1; j>=0; j--)
            {
                if(arr[j].h<=arr[ind[v]].h) ans2++;
                else break;
            }
            for(int j=ind[v]+1; j<m; j++)
            {
                if(arr[j].h>=arr[ind[v]].h)
                {
                    ans1 = arr[j].id;
                    break;
                }
            }
            printf("%d %d\n", ans1, ans2);
        }
    }
    return 0;
}

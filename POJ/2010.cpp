#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> node;

int n, c, f;
int lb[100010];
node a[100010];

bool cmp(node u, node v)
{
    return u.first<v.first;
}

int main()
{
    while(scanf("%d%d%d", &n, &c, &f)!=EOF)
    {
        for(int i=0; i<c; i++)
        {
            int s, co;
            scanf("%d%d", &s, &co);
            a[i].first = s;
            a[i].second = co;
        }
        sort(a, a+c, cmp);

        priority_queue<int> pq;
        int sum = 0;
        for(int i=0; i<c; i++)
        {
            if(pq.size()<n/2)
            {
                pq.push(a[i].second);
                sum += a[i].second;
                continue;
            }
            lb[i] = sum;
            if(a[i].second<pq.top())
            {
                sum -= pq.top();
                pq.pop();
                pq.push(a[i].second);
                sum += a[i].second;
            }
        }
        int ans = -1;
        sum = 0;
        while(!pq.empty()) pq.pop();
        for(int i=c-1; i>=0; i--)
        {
            if(pq.size()<n/2)
            {
                pq.push(a[i].second);
                sum += a[i].second;
                continue;
            }
            if(lb[i]!=0 && lb[i]+sum+a[i].second<=f)
            {
                ans = a[i].first;
                break;
            }
            if(a[i].second<pq.top())
            {
                sum -= pq.top();
                pq.pop();
                pq.push(a[i].second);
                sum += a[i].second;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> wall;

int t, n, k;
int a, b, c, d;
int arr[110];
vector<int> vec[110];
wall w[110];
bool wa[110];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        memset(arr, 0, sizeof(arr));
        memset(wa, 0, sizeof(wa));
        for(int i=0; i<=100; i++) vec[i].clear();
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            for(int j=min(a, c); j<=max(a, c); j++)
            {
                arr[j]++;
                vec[j].push_back(i);
            }
            w[i] = wall(min(a, c), max(a, c));
        }
        
        int ans = 0;
        for(int i=0; i<=100; i++)
        {
            if(arr[i]<=k) continue;
            int length = -1;
            int index = -1;
            for(int j=0; j<vec[i].size(); j++)
            {
                if(!wa[vec[i][j]] && length<w[vec[i][j]].second)
                {
                    index = vec[i][j];
                    length = w[vec[i][j]].second;
                }
            }
            wa[index] = true;
            for(int j=i; j<=w[index].second; j++) arr[j]--;
            ans++;
            i--;
        }
        printf("%d\n", ans);
    }
    return 0;
}

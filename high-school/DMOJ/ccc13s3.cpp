#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> match;

int t, num;
int p[5];
bool g[5][5];
int ans;
vector<match> vec;

void dfs(int ind)
{
    if(ind==vec.size())
    {
        bool flag = true;
        for(int i=1; i<=4; i++)
        {
            if(t==i) continue;
            if(p[t]<=p[i]) flag = false;
        }
        if(flag) ans++;
        return;
    }
    int a, b;
    a = vec[ind].first;
    b = vec[ind].second;
    p[a]+=3;
    dfs(ind+1);
    p[a]-=3;
    p[a]++;
    p[b]++;
    dfs(ind+1);
    p[a]--;
    p[b]--;
    p[b]+=3;
    dfs(ind+1);
    p[b]-=3;
}

int main()
{
    scanf("%d%d", &t, &num);
    int a, b, c, d;
    for(int i=0; i<num; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(c>d) p[a]+=3;
        else if(c==d) p[a]++, p[b]++;
        else p[b]+=3;
        g[a][b] = g[b][a] = true;
    }
    ans = 0;
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<i; j++)
        {
            if(!g[i][j]) vec.push_back(match(i, j));
        }
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}

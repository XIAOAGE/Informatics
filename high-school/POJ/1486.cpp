#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int minx[5010];
int maxx[5010];
int miny[5010];
int maxy[5010];
int x[5010];
int y[5010];
bool g[5010][5010];
int match[5010];
bool v2[5010];

bool dfs(int idx)
{
    for(int i=0; i<n; i++)
    {
        if(g[idx][i] && match[i]==-1)
        {
            match[i] = idx;
            return true;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(g[idx][i] && v2[i])
        {
            v2[i] = false;
            if(dfs(match[i]))
            {
                match[i] = idx;
                v2[i] = true;
                return true;
            }
            v2[i] = true;
        }
    }

    return false;
}

void check()
{
    bool ret = true;
    int temp[300];
    for(int i=0; i<n; i++) {temp[i] = match[i];}
    for(int i=0; i<n; i++)
    {
        g[match[i]][i] = false;
        int tmp = match[i];
        match[i] = -1;
        if(!dfs(tmp))
        {
            ret = false;
            if(i!=n-1) printf("(%c,%d) ", (i+65), tmp+1);
            else printf("(%c,%d)", (i+65), tmp+1);
        }
        for(int i=0; i<n; i++) match[i]=temp[i];
        g[tmp][i] = true;
    }
    if(ret) printf("none\n");
    else printf("\n");
}

int main()
{
    int testcase = 1;
    while(scanf("%d", &n)!=EOF && n)
    {
        memset(v2, true, sizeof v2);
        memset(match, -1, sizeof match);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                g[i][j] = false;
        int a, b, c, d;
        for(int i=0; i<n; i++)  scanf("%d%d%d%d", &minx[i], &maxx[i], &miny[i], &maxy[i]);
        for(int i=0; i<n; i++)  scanf("%d%d", &x[i], &y[i]);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(x[i]>minx[j] && x[i]<maxx[j] && y[i]>miny[j] && y[i]<maxy[j]) {g[i][j] = true;}

        bool is_solvable = true;
        for(int i=0; i<n; i++)
        {
            if(!dfs(i))
            {
                is_solvable = false;
                break;
            }
        }
        printf("Heap %d\n", testcase++);
        check();
        printf("\n");
    }
    return 0;
}

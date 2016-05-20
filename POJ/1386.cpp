#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VM 30

int indeg[VM],outdeg[VM],mat[VM][VM],start;
bool vis[VM];

void dfs (int u)
{
    for (int i = 0; i < 26; i ++)
        if (mat[u][i])
        {
            mat[u][i] = 0;
            dfs(i);
        }

}
bool cmp()
{
    int i,k,sum1,sum2,sum3;
    sum1 = sum2 = sum3 = 0;
    for (i = 0; i < 26; i ++)
    {
        if (indeg[i] - outdeg[i] == 1)
            sum1 ++;
        if (outdeg[i] - indeg[i] == 1)
        {
            sum2 ++;
            start = i;
        }
        if (indeg[i] == outdeg[i]&&indeg[i]!= 0)
            k = i;
        if (abs(indeg[i] - outdeg[i]) > 1)
            sum3 ++;
    }

    if (sum1 > 1||sum2 > 1||sum3 > 0)
        return false;
    if (sum2 == 0)
        start = k;
    return true;
}
int main ()
{
    int T,n;
    bool flag;
    char str[1005];
    scanf ("%d",&T);
    while (T --)
    {
        scanf ("%d",&n);
        memset (indeg,0,sizeof(indeg));
        memset (outdeg,0,sizeof(outdeg));
        memset (mat,0,sizeof(mat));
        memset (vis,false,sizeof(vis));
        while (n --)
        {
            scanf ("%s",str);
            int len = strlen(str);
            int u = str[0]-'a';
            int v = str[len-1]-'a';
            mat[u][v] = 1;
            indeg[v] ++;
            outdeg[u] ++;
        }
        flag = false;
        if (cmp ())
        {
            flag = true;
            dfs(start);
            for (int i = 0; i < 26; i ++)
                for (int j = 0; j < 26; j ++)
                    if (mat[i][j])
                    {
                        flag = false;
                        break;
                    }
        }
        if (flag)
            printf ("Ordering is possible.\n");
        else
            printf ("The door cannot be opened.\n");
    }
    return 0;
}

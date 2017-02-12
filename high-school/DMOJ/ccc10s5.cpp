#include <bits/stdc++.h>

using namespace std;

struct node
{
    int lkid, rkid, val;
};

string line;
node tree[1000];
int x, u, id;
int dp[400][3000];
int l[400][3000];
int r[400][3000];
int vl[400];
int vr[400];

int to_num(string str)
{
    int mul = 0;
    int ret = 0;
    for(int i=str.length()-1; i>=0; i--)
    {
        ret += (str[i]-48) * pow(10, mul++);
    }
    return ret;
}

void build_tree()
{
    while(line[u]!='(' && (line[u]<48 || line[u]>57)) u++;
    int tmp = id;
    tree[tmp].val = 0;
    if(line[u]=='(')
    {
        u++;
        tree[tmp].lkid = ++id;
        build_tree();
        u++;
        tree[tmp].rkid = id;
        build_tree();
    }
    else
    {
        string str = "";
        while(line[u]>=48 && line[u]<=57) str+=line[u++];
        tree[tmp].lkid = -1;
        tree[tmp].rkid = -1;
        tree[tmp].val = to_num(str);
        id++;
    }
}

int solve(int ind, int nu)
{
    if(dp[ind][nu]) return dp[ind][nu];
    if(tree[ind].lkid==-1)
    {
        dp[ind][nu] = tree[ind].val+nu;
        return tree[ind].val+nu;
    }
    int lkid = tree[ind].lkid;
    int rkid = tree[ind].rkid;
    for(int i=vl[ind]; i<=nu; i++)
    {
        for(int j=0; j<=i; j++)
        {
            l[ind][i] = max(l[ind][i+j], min((int)pow((1+i-j),2), solve(lkid, j)));
        }
    }
    vl[ind] = nu+1;

    for(int i=vr[ind]; i<=nu; i++)
    {
        for(int j=0; j<=i; j++)
        {
            r[ind][i] = max(r[ind][i+j], min((int)pow((1+i-j),2), solve(rkid, j)));
        }
    }
    vr[ind] = nu+1;

    for(int i=0, j=nu; i<=nu; i++, j--)
    {
        dp[ind][nu] = max(dp[ind][nu], l[ind][i]+r[ind][j]);
    }
    return dp[ind][nu];
}

int main()
{
    getline(cin, line);
    scanf("%d", &x);
    u = 0, id = 1;
    build_tree();
    solve(1, x);
    printf("%d\n", dp[1][x]);
    return 0;
}

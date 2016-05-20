#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
  
struct node  
{  
    int num, value, next;  
};  
  
const int maxn = 1000010;  
  
  
int head[maxn], parent[maxn], r[maxn], e, num, n, m, v;  
node edge[maxn];  
  
int hash(int x);  
  
int findSet(int x);  
  
bool unionSet(int x, int y);  
  
int main()  
{  
    char s[10];  
    int hx, hy;  
    bool flag = false;  
    e = 0;  
    num = 0;  
    memset(head, -1, sizeof(head));  
    for(int i = 0; i < maxn; i++)  
        parent[i] = i;  
    scanf("%d %d", &n, &m);  
    for(int i = 0; i < m; i++)  
    {  
        int x, y;  
        scanf("%d %d %s", &x, &y, s);  
        v = 0;  
        if(s[0] == 'o')  
            v = 1;  
        hx = hash(x - 1);  
        hy = hash(y);  
        if(unionSet(hx, hy))  
        {  
            if((r[hx] ^ r[hy]) != v)  
            {  
                printf("%d\n", i);  
                flag = true;  
                break;  
            }  
        }  
    }  
    if(!flag)  
        printf("%d\n", m);  
    return 0;  
}  
  
int hash(int x)  
{  
    int h = x % maxn;  
    for(int i = head[h]; i != -1; i = edge[i].next)  
    {  
        if(x == edge[i].value)  
            return edge[i].num;  
    }  
    edge[e].value = x;  
    edge[e].num = num++;  
    edge[e].next = head[h];  
    head[h] = e++;  
    return (num - 1);  
}  
  
int findSet(int x)  
{  
    if(x != parent[x])  
    {  
        int tmp = findSet(parent[x]);  
        r[x] ^= r[parent[x]];  
        parent[x] = tmp;  
    }  
    return parent[x];  
}  
  
bool unionSet(int x, int y)  
{  
    int px = findSet(x), py = findSet(y);  
    if(px != py)  
    {  
        parent[py] = px;  
        r[py] = r[x] ^ r[y] ^ v;  
        return false;  
    }  
    return true;  
}  

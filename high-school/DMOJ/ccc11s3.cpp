#include <bits/stdc++.h>

using namespace std;

int t;
int m, x, y;

bool dfs(int n, int x, int y)
{
    int lv = pow(5, n);
    int posx = x/lv;
    int posy = y/lv;
    x = x - x/lv*lv;
    y = y - y/lv*lv;
    if(posy==0 && (posx==1 || posx==2 || posx==3)) return true;
    else if(posy==1 && posx==2) return true;
    else if(n!=0 && posx==1 && posy==1) return dfs(n-1, x, y);
    else if(n!=0 && posx==2 && posy==2) return dfs(n-1, x, y);
    else if(n!=0 && posx==3 && posy==1) return dfs(n-1, x, y);
    else return false;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &m, &x, &y);
        if(dfs(m-1, x, y))
        {
            cout<<"crystal"<<endl;
        }
        else
        {
            cout<<"empty"<<endl;
        }
    }
    return 0;
}

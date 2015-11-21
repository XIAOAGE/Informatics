#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> node;

int k, state;
bool v[50000000];

int deal(int a)
{
    int l = 0, r = 0;
    for(int i=0; i<k; i++)
    {
        if(a>>i & 1)
        {
            r++;
        }
        else
        {
            if(r-l>=4) break;
            l = i+1;
            r = i+1;
        }
    }
    if(r-l>=4)
    {
        for(int i=l; i<r; i++)
        {
            a -= pow(2, i);
        }
    }
    return a;
}

int main()
{
    cin>>k;
    int tmp;
    state = 0;
    for(int i=0; i<k; i++)
    {
        cin>>tmp;
        if(tmp) state += pow(2, i);
    }
    queue<node> qu;
    state = deal(state);
    qu.push(node(state, 0));
    v[state] = true;
    while(true)
    {
        node cur = qu.front(); qu.pop();
        if(cur.first==0)
        {
            cout<<cur.second<<endl;
            break;
        }
        for(int i=0; i<k; i++)
        {
            if(cur.first>>i & 1) continue;
            else
            {
                if(v[cur.first+(int)pow(2, i)]) continue;
                tmp = deal(cur.first+pow(2, i));
                if(v[tmp]) continue;
                else qu.push(node(tmp, cur.second+1));
                v[cur.first+(int)pow(2, i)] = true;
                v[tmp] = true;
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> node;

int n;
int s;
bool v[3000000];

int n_to_deci(string str)
{
    int ret = 0;
    int cnt = 0;
    for(int i=str.length()-1; i>=0; i--)
    {
        ret += (str[i]-48)*pow(n, cnt++);
    }
    return ret;
}

string deci_to_n(int a)
{
    string ret = "";
    while(a!=0)
    {
        int re = a%n;
        a/=n;
        ret += (char)(re+48);
    }
    while(ret.length()<n) ret+="0";
    /*
    string ret2 = "";
    for(int i=ret.length()-1; i>=0; i--)
    {
        ret2 += ret[i];
    }
    return ret2;
    */
    return ret;
}

int main()
{
    while(scanf("%d", &n)!=EOF && n!=0)
    {
        int tmp;
        s = 0;
        memset(v, 0, sizeof v);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &tmp);
            tmp--;
            s += i*pow(n, tmp);
        }
        int dest = 0;
        for(int i=0; i<n; i++) dest += i*pow(n, i);
        queue<node> qu;
        qu.push(node(s, 0));
        bool not_found = true;
        while(!qu.empty())
        {
            node cur = qu.front(); qu.pop();
            int state = cur.first;
            if(v[state]) continue;
            if(state==dest)
            {
                printf("%d\n", cur.second);
                not_found = false;
                break;
            }
            v[state] = true;
            string code = deci_to_n(state);
            bool v2[10];
            memset(v2, 0, 10);
            for(int i=0; i<n; i++)
            {
                int pos = code[i]-48;
                if(v2[pos]) continue;
                v2[pos] = true;
                if(pos+1<n)
                {
                    bool flag = true;
                    for(int j=0; j<n; j++)
                    {
                        if(code[j]-48==pos+1 && j<i)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                    {
                        int temp = state + pow(n, i);
                        if(!v[temp]) qu.push(node(temp, cur.second+1));
                    }
                }
                if(pos-1>=0)
                {
                    bool flag = true;
                    for(int j=0; j<n; j++)
                    {
                        if(code[j]-48==pos-1 && j<i)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                    {
                        int temp = state - pow(n, i);
                        if(!v[temp]) qu.push(node(temp, cur.second+1));
                    }
                }
            }
        }
        if(not_found) printf("IMPOSSIBLE\n");
    }
    return 0;
}

/*
 碰到括号的输入题可以用stack，很简便，0ms秒过
 */
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int, int> matrix;

int N;
matrix arr[26];
string chain;
stack<matrix> sta;
int ans;

void deal_string()
{
    string line;
    char a;
    int b, c;
    for(int i=0; i<N; i++)
    {
        getline(cin, line);
        stringstream s;
        s.str(line);
        s>>a>>b>>c;
        arr[a-65] = matrix(b, c);
    }
}

bool manipulate()
{
    if(sta.size()==1) return false;
    matrix a, b;
    a = sta.top(); sta.pop();
    b = sta.top(); sta.pop();
    if(b.second!=a.first) return true;
    ans += b.first*b.second*a.second;
    sta.push(matrix(b.first, a.second));
    return false;
}

int main()
{
    string line;
    getline(cin, line);
    N = atoi(line.c_str());
    deal_string();
    
    while(getline(cin, chain))
    {
        ans = 0;
        bool judge = true;
        for(int i=0; i<chain.length(); i++)
        {
            if(chain[i]=='(')
            {
                continue;
            }
            else if(chain[i]==')')
            {
                if(manipulate())
                {
                    cout<<"error"<<endl;
                    judge = false;
                    break;
                }
            }
            else
            {
                sta.push(arr[chain[i]-65]);
            }
        }
        if(judge)
        {
            cout<<ans<<endl;
        }
        while(!sta.empty())
        {
            sta.pop();
        }
    }
    return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 300;
int n;
int N;
int total_length;
int length;
string arr[MAX];
bool used[MAX];

void input();
/*
2

011
0111
01110
111
0111
10111
 
011
0111
01110
111
0111
10111

 */
bool dfs(string text, int index)
{
    bool res = false;
    for(int i=0; i<N; i++)
    {
        if(used[i] || i==index) continue;
        if(arr[index]+arr[i]!=text) continue;
        int tmp = 1;
        used[index] = used[i] = true;
        while(used[tmp]) tmp++;
        res = res || dfs(text, tmp);
        if(res) break;
        used[index] = used[i] = false;
    }
    bool succeed = true;
    for(int i=0; i<N; i++)
    {
        if(!used[i])
        {
            succeed = false;
            break;
        }
    }
    if(succeed)
    {
       return succeed;
    }
    return res;
}

void solve()
{
    string text = "";
    for(int i=N-1; i<N; i++)
    {
        text = arr[0] + arr[i];
        if(text.length()!=length) continue;
        used[0] = used[i] = true;
        int tmp = 1;
        while(used[tmp]) tmp++;
        if(dfs(text, tmp))
        {
            cout<<text<<endl;
            cout<<endl;
            return;
        }
        used[0] = used[i] = false;
    }
    for(int i=N-1; i<N; i++)
    {
        text = arr[i] + arr[0];
        if(text.length()!=length) continue;
        used[0] = used[i] = true;
        int tmp = 1;
        while(used[tmp]) tmp++;
        if(dfs(text, tmp))
        {
            cout<<text<<endl;
            cout<<endl;
            return;
        }
        used[0] = used[i] = false;
    }
}

int main()
{
    freopen("/Users/dzuyokoxiao/Desktop/input.in", "r", stdin);
    cin>>n;
    cin.ignore();
    cin.ignore();
    while(n--)
    {
        input();
        solve();
    }
    return 0;
}

void input()
{
    for(int i=0; i<MAX; i++)
    {
        arr[i] = "";
    }
    N = 0;
    total_length = 0;
    memset(used, false, sizeof(used));
    string line = "";
    while(getline(cin, line))
    {
        if(line=="") break;
        arr[N++] = line;
        total_length+=line.length();
    }
    length = total_length/(N/2);
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> node;

struct cmp
{
    bool operator()(node a, node b)
    {
        if(a.first!=b.first)
        {
            return a.first<b.first;
        }
        else
        {
            return a.second>b.second;
        }
    }
};

int n, h;
int f[30];
int d[30];
int t[30];

void input();

void solve()
{
    int number = -1;
    int ans[30];
    for(int i=0; i<n; i++)
    {
        priority_queue<node, vector<node>, cmp> pq;
        int tmp[30];
        for(int i=0; i<30; i++) tmp[i] = 0;
        int time = h*60 - t[i]*5;
        int temp = 0;
        for(int j=0; j<=i; j++)
        {
            pq.push(node(f[j], j));
        }

        while(time>0)
        {
            node current = pq.top(); pq.pop();
            temp += current.first;
            current.first -= d[current.second];
            if(current.first>0) pq.push(current);
            else if(current.first<=0 && current.second==0)
            {
                current.first = 0;
                pq.push(current);
            }
            tmp[current.second]+=5;
            time-=5;
        }
        if(number<temp)
        {
            number = temp;
            for(int i=0; i<n; i++)
            {
                ans[i] = tmp[i];
            }
        }
    }
    for(int i=0; i<n-1; i++)
    {
        cout<<ans[i]<<", ";
    }
    cout<<ans[n-1]<<endl;
    cout<<"Number of fish expected: "<<number<<endl;
    cout<<endl;
}

int main()
{
    while(cin>>n, n)
    {
        cin>>h;
        input();
        solve();
    }
    return 0;
}

void input()
{
    for(int i=0; i<n; i++)
    {
        cin>>f[i];
    }
    
    for(int i=0; i<n; i++)
    {
        cin>>d[i];
    }
    t[0] = 0;
    for(int i=1; i<n; i++)
    {
        cin>>t[i];
        t[i] = t[i]+t[i-1];
    }
}

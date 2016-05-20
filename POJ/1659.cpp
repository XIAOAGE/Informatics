#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> frog;

int T;
int N;
frog arr[10];
int graph[10][10];

void input();

void solve()
{
    for(int i=0; i<N; i++)
    {
        int tmp = 1;
        sort(arr, arr+N, greater<frog>());
        while(tmp<=arr[i].first && i+tmp<N)
        {
            if(arr[i+tmp].first-1<0)
            {
                cout<<"NO"<<endl;
                return;
            }
            arr[i+tmp].first--;
            graph[arr[i].second][arr[i+tmp].second] = 1;
            graph[arr[i+tmp].second][arr[i].second] = 1;
            tmp++;
        }
        
        if(tmp<=arr[i].first)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    
    cout<<"YES"<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<graph[i][j];
            if(j!=N-1)
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    cin>>T;
    while(T--)
    {
        input();
        solve();
        if(T)
        {
            cout<<endl;
        }
    }
    return 0;
}

void init()
{
    for(int i=0; i<10; i++)
    {
        arr[i] = frog(0,0);
        for(int j=0; j<10; j++)
        {
            graph[i][j] = 0;
        }
    }
}

void input()
{
    cin>>N;
    init();
    int a;
    for(int i=0; i<N; i++)
    {
        cin>>a;
        arr[i] = frog(a, i);
    }
}

#include <iostream>

using namespace std;

int P, T;
bool map[110][110];
int parent[110];

void merge(int a, int b)
{
    parent[b] = a;
}

int main()
{
    cin>>P>>T;
    int a, b;
    while(cin>>a>>b)
    {
        map[a][b] = true;
    }

    for(int i=1; i<=P; i++)
    {
        for(int j=i+1; j<=P; j++)
        {
            if(parent[a]==parent[b] && parent[a]!=0) continue;
            bool flag = true;
            for(int k=1; k<=T; k++)
            {
                if(map[i][k]!=map[j][k])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                merge(i, j);
            }
        }
    }
    
    int ans = 0;
    for(int i=1; i<=P; i++)
    {
        if(!parent[i]) ans++;
    }
    
    cout<<ans<<endl;
    return 0;
}

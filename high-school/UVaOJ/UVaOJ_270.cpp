#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

typedef pair<int, int> node;
vector<node> vec;
int ans;

bool on_line(int x1, int y1, int x2, int y2)
{
    return (x1*y2-x2*y1)==0;
}

int N;

void input()
{
    string line;
    int a, b;
    while(getline(cin, line))
    {
        if(line=="") break;
        stringstream s;
        s.str(line);
        s>>a>>b;
        vec.push_back(node(a,b));
    }
}

int main()
{
    //freopen("/Users/dzuyokoxiao/Desktop/input.in", "r", stdin);
    cin>>N;
    cin.ignore();
    cin.ignore();
    while(N--)
    {
        vec.clear();
        input();
        ans = 0;
        if(vec.size()==1)
        {
            ans=1;
        }
        for(int i=0; i<vec.size(); i++)
        {
            for(int j=i+1; j<vec.size(); j++)
            {
                int tmp = 2;
                for(int k=j+1; k<vec.size(); k++)
                {
                    if(on_line(vec[j].first-vec[i].first, vec[j].second-vec[i].second, vec[k].first-vec[i].first, vec[k].second-vec[i].second))
                    {
                        tmp++;
                    }
                }
                ans = max(ans, tmp);
            }
        }
        printf("%d\n", ans);
        if(N!=0)
        {
            cout<<endl;
        }
    }
    return 0;
}
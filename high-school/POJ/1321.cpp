#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> grid;

int n, k;
bool row[1100];
bool col[1100];
vector<grid> vec;
string line;

int solve(int num, int index)
{
    if(num==k)  return 1;
    if(index==vec.size() || vec.size()-index<k-num) return 0;
    int x = vec[index].first;
    int y = vec[index].second;
    int ret = 0;
    if(row[x] || col[y])
    {
        ret+=solve(num, index+1);
    }
    else
    {
        ret+=solve(num, index+1);
        row[x] = true;
        col[y] = true;
        ret+=solve(num+1, index+1);
        row[x] = false;
        col[y] = false;
    }
    return ret;
}

int main()
{
    while(cin>>n>>k && n!=-1)
    {
        cin.ignore();
        vec.clear();
        for(int i=0; i<n; i++)
        {
            getline(cin, line);
            row[i] = false;
            for(int j=0; j<n; j++)
            {
                col[j] = false;
                if(line[j]=='#')
                {
                    vec.push_back(grid(i,j));
                }
            }
        }
        cout<<solve(0,0)<<endl;
    }
    return 0;
}

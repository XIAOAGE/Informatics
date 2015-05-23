/*
 建造两个vector，一个放出发点，另一个放到达点，如果yes的话两个数组在排序好后的值是一样的。额，原来那么水
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> vec1;
vector<int> vec2;
int n;

int main()
{
    while(cin>>n, n)
    {
        int a, b;
        vec1.clear();
        vec2.clear();
        for(int i=0; i<n; i++)
        {
            cin>>a>>b;
            vec1.push_back(a);
            vec2.push_back(b);
        }
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        bool flag = true;
        for(int i=0; i<vec1.size(); i++)
        {
            if(vec1[i]!=vec2[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
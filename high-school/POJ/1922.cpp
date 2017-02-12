#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> student;
int N, v, t;
int cnt;
student arr[10010];
double t1[10010];

bool comp(student a, student b)
{
    return a.second<b.second;
}

int main()
{
    while(cin>>N, N!=0)
    {
        cnt = 0;
        for(int i=0; i<N; i++)
        {
            cin>>v>>t;
            if(t<0) continue;
            arr[cnt++] = student(v, t);
        }
        sort(arr, arr+cnt, comp);
        for(int i=0; i<cnt; i++)
        {
            t1[i] = ceil(4.5/arr[i].first*3600+arr[i].second);
        }
        double min_time = t1[0];
        for(int i=1; i<cnt; i++)
        {
            min_time = min(min_time, t1[i]);
        }
        cout<<min_time<<endl;
    }
    return 0;
}

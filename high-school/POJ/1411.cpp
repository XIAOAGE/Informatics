#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int m, a, b;
bool arr[100010];
vector<int> vec;

void presolve()
{
    arr[0] = arr[1] = true;
    for(int i=2; i<=100000; i++)
    {
        if(arr[i]) continue;
        vec.push_back(i);
        for(int j=2*i; j<=100000; j+=i) arr[j] = true;
    }
}

int main()
{
    presolve();
    while(scanf("%d%d%d", &m, &a, &b), m&&a&&b)
    {
        int p = -1, q=-1;
        int ma = -1;
        for(int i=0; vec[i]<=sqrt(m); i++)
        {
            for(int j=i; vec[i]*vec[j]<=m; j++)
            {
                if(a*vec[j]<=b*vec[i] && ma<vec[i]*vec[j])
                {
                    ma = vec[i]*vec[j];
                    p = vec[i];
                    q = vec[j];
                }
            }
        }
        printf("%d %d\n", p, q);
    }
    return 0;
}

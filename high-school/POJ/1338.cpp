#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vec;
int pindex[3];
int prime[] = {2,3,5};

void solve()
{
   vec.push_back(1);
   while(vec.size()<1500)
   {
       int tmp = 2147483647;
       for(int i=0; i<3; i++)
       {
           for(int j=pindex[i]; j<vec.size(); j++)
           {
               if(vec[j]*prime[i]<=vec[vec.size()-1]) continue;
               tmp = min(tmp, prime[i]*vec[j]);
               pindex[i] = j;
               break;
           }
       }
       vec.push_back(tmp);
   }
}

int N;

int main()
{
    solve();
    while(cin>>N, N)
    {
       cout<<vec[N-1]<<endl;
    }
    return 0;
}

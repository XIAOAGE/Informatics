/*
题意： 给出一系列的素数， humble numbers是一系列的数，每一个数满足它的素因数都是给出的一系列的素数中的一个，
      求出第N个hunmble number. 1 不算是humble number
思路： 本来还想着用线段树什么的， 看了题解后发现可以一个一个地求出humble number。 为了方便运算， 先把1放入humble number中
      然后得出一个比当前最大的humble number大的最小数
      两个优化在代码中标了了一下。
/*
 ID: qiangbr1
 PROG: humble
 LANG: C++11
 */


#include <iostream>
#include <vector>
#include <algorithm>

#define USACO
#define FILEIN "humble.in"
#define FILEOUT "humble.out"

using namespace std;

const int MAX = 100;
int K,N;
int arr[MAX];
int pindex[MAX];    //*************优化1***************//
vector<int> vec;

int main()
{
#ifdef USACO
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
#endif
    cin>>K>>N;
    for(int i=0; i<K; i++)
    {
        cin>>arr[i];
        pindex[i] = 0;
    }
    vec.push_back(1);
    int number = 0;
    int last = 1;
    while(number<N)
    {
        int tmp = 2147483647;
        for(int i=0; i<K; i++)
        {
            for(int j=pindex[i]; j<vec.size(); j++)
            {
                if(arr[i]*vec[j]>last)
                {
                    tmp = min(tmp, arr[i]*vec[j]);
                    break;          //*************优化2***************//
                }
                else
                {
                    pindex[i]++;
                }
            }
        }
        vec.push_back(tmp);
        last = tmp;
        number++;
    }
    cout<<vec[N]<<endl;
    return 0;
}

/*
 题意：Give an N(N<=100000) number sequence, find the number of pair of (i,j),   
      for which i<j and ai>aj.
 思路：利用merge sort中的分治法的思想，实际上整个求解的过程只是跑一遍merge sort。在merge sort中
      注意，找到一个左边的元素比右边的元素大时，就要加上剩下的左边的元素。
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int arr[MAX];
int sorted[MAX];
int N;
int ans;

void f(int left, int right)
{
    if(left==right)
    {
        sorted[left] = arr[left];
        return;
    }
    int mid = (left+right)/2;
    f(left, mid);
    f(mid+1,right);
    int index = left;
    int index1 = left;
    int index2 = mid+1;
    while(index1<=mid && index2<=right)
    {
        if(arr[index1]>arr[index2])
        {
            ans += mid-index1+1;
            sorted[index++] = arr[index2++];
        }
        else
        {
            sorted[index++] = arr[index1++];
        }
    }
    
    while(index1++<=mid)
    {
        sorted[index++] = arr[index1++];
    }
    
    while(index2++<=right)
    {
        sorted[index++] = arr[index2++];
    }
}

int main()
{
    ans = 0;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    f(0, N-1);
    cout<<ans<<endl;
    if (is_sorted(sorted, sorted + N)){
        cout << (N * (N - 1)) / 2 << endl;
    }
    return 0;
}


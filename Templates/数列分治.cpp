/*
 定理：一个乱序序列的 逆序数 = 在只允许相邻两个元素交换的条件下,得到有序序列的交换次数
 Problem ID: POJ 1804
 
 求逆序数用数列分治：思路：利用merge sort中的分治法的思想，实际上整个求解的过程只是跑一遍merge sort。在merge sort中
 注意，找到一个左边的元素比右边的元素大时，就要加上剩下的左边的元素。
 */

#include <iostream>

using namespace std;

const int MAX = 2000;
int N;
int arr[MAX];
int sorted[MAX];
int ans;

void solve(int left, int right)
{
    if(left==right)
    {
        sorted[left] = arr[left];
        return;
    }
    int mid = (left+right)/2;
    solve(left, mid);
    solve(mid+1, right);
    int index1 = left;
    int index2 = mid+1;
    int index = left;
    int temp[MAX];
    while(index1<=mid && index2<=right)
    {
        if(sorted[index1]>sorted[index2])
        {
            ans+=mid-index1+1;
            temp[index++] = sorted[index2++];
        }
        else
        {
            temp[index++] = sorted[index1++];
        }
    }
    
    while(index1<=mid)
    {
        temp[index++] = sorted[index1++];
    }
    
    while(index2<=right)
    {
        temp[index++] = sorted[index2++];
    }
    
    for(int i=left; i<=right; i++)
    {
        sorted[i] = temp[i];
    }
        
}

int main()
{
    cin>>N;
    int cnt = 1;
    int t;
    while(N--)
    {
        ans = 0;
        cout<<"Scenario #"<<cnt++<<":"<<endl;
        cin>>t;
        for(int i=0; i<t; i++)
        {
            cin>>arr[i];
        }
        solve(0, t-1);
        cout<<ans<<endl;
        cout<<endl;
    }
    return 0;
}

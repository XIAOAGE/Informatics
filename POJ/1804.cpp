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

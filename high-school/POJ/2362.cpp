#include <iostream>
#include <algorithm>

using namespace std;

int N, M, sum;
int arr[20];
bool used[20];

bool dfs(int index, int length, int number)
{
    if(number==3) return true;
    if(length==sum/4) return dfs(0, 0, number+1);
    if(index==M) return false;
    if(used[index]) return dfs(index+1, length, number);
    if(dfs(index+1, length, number)) return true;
    if(length+arr[index]<=sum/4)
    {
        used[index] = true;
        if(dfs(index, length+arr[index], number)) return true;
        used[index] = false;
    }
    return false;
}

bool compare(int a, int b)
{
    return a>b;
}

int main()
{
    cin>>N;
    while(N--)
    {
        cin>>M;
        sum = 0;
        for(int i=0; i<M; i++)
        {
            cin>>arr[i];
            sum += arr[i];
        }
        sort(arr, arr+M, compare);
        for(int i=0; i<M; i++) used[i] = false;
        if(sum%4 || arr[0]>sum/4)
        {
            cout<<"no"<<endl;
            continue;
        }
        if(dfs(0,0,0))    cout<<"yes"<<endl;
        else    cout<<"no"<<endl;
    }
    return 0;
}

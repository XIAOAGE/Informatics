#include <iostream>
#include <vector>

using namespace std;

int arr[13];

void dfs(int number[], int has, int rest, int current)
{
    if(6-has>rest) return;
    if(has==6)
    {
        for(int i=0; i<6; i++)
        {
            cout<<number[i]<<" ";
        }
        cout<<endl;
        return;
    }
    number[has] = arr[current];
    dfs(number, has+1, rest-1, current+1);
    number[has] = 0;
    dfs(number, has, rest-1, current+1);
}

int main()
{
    int N;
    cin>>N;
    while(N)
    {
        for(int i=0; i<N; i++)
        {
            cin>>arr[i];
        }
        int arr[6];
        dfs(arr, 0, N, 0);
        cin>>N;
        if(N)
        {
            cout<<endl;
        }
    }
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n;
int arr1[1010];
int arr2[1010];
bool visited[1010];
bool tied[1010];

int main()
{
    while(scanf("%d", &n), n)
    {
        memset(visited, 0, sizeof(visited));
        memset(tied, 0, sizeof(tied));
        for(int i=0; i<n; i++) scanf("%d", &arr1[i]);
        for(int i=0; i<n; i++) scanf("%d", &arr2[i]);
        sort(arr1, arr1+n);
        sort(arr2, arr2+n);
        
        int win = 0;
        for(int i=0; i<n; i++)
        {
            int index = -1;
            bool is_tie = false;
            for(int j=0; j<n; j++)
            {
                if(visited[j]) continue;
                if(arr2[j]>arr1[i]) break;
                else if(arr1[i]>arr2[j])
                {
                    index = j;
                }
                else if(arr1[i]==arr2[j])
                {
                    if(index!=-1) break;
                    if(tied[j]) continue;
                    is_tie = true;
                    tied[j] = true;
                    break;
                }
            }
            if(index==-1 || is_tie) continue;
            win++;
            tied[index] = false;
            visited[index] = true;
        }
        int tie = 0;
        for(int i=0; i<n; i++)
        {
            if(tied[i])
            {
                tie++;
            }
        }
        printf("%d\n", win*200-(n-tie-win)*200);
    }
    return 0;
}

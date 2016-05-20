#include <cstdio>
#include <algorithm>

using namespace std;

int nxt[3010];
int arr[3010];
int n;

void solve(int cnt)
{
    if(cnt==n) return;
    int tmp[3010];
    for(int i=0; i<n; i++)  tmp[i] = arr[i];
    for(int i=0; i<n; i++)  arr[nxt[i]] = tmp[i];
    printf("%d ", tmp[0]);
    solve(cnt+1);
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int cnt = 0;
    for(int i=0; i<n; i++)  if(!arr[i]) nxt[i] = cnt++;
    for(int i=0; i<n; i++)  if(arr[i]) nxt[i] = cnt++;
    sort(arr, arr+n);
    solve(0);
    return 0;
}

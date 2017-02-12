#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 1000010
using namespace std;
int arr[MAXN];

int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0; i<n; ++i)
            scanf("%d",&arr[i]);
        sort(arr, arr+n);
        int mid, left, right;
        int ans_min, ans_num, ans_val;
        if(n%2==0){ // 如果有偶数个数字
            left=(n-2)/2;  right=(n)/2;
            ans_min=arr[left];
            ans_num=0;
            for(int i=left; arr[i]==arr[left]&&i>=0; --i) ++ans_num;
            for(int i=right; arr[i]==arr[right]&&i<n; ++i) ++ans_num;
            ans_val = arr[right]-arr[left]+1;
        }
        else{
            mid = (n-1)/2;
            ans_min = arr[mid];
            ans_num=0;
            for(int i=mid; arr[i]==arr[mid]&&i>=0; --i) ++ans_num;
            for(int i=mid+1; arr[i]==arr[mid]&&i<n; ++i) ++ans_num;
            ans_val = 1;
        }
        printf("%d %d %d\n", ans_min, ans_num, ans_val);
    }
    return 0;
}

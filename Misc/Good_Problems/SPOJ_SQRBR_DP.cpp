/*
 *题意概述：给你一个n，2*n是整个括号字符串的长度，还有一个升序的integer序列，代表这些位置上必须是一个
 *opening bracket. 问有多少中正确字符串的组合。
 *
 *题解是从这里看来的： http://www.quora.com/Can-some-one-explain-how-to-solve-square-brackets-problem-on-spoj-SPOJ-SQRBR
 *
 *个人理解就是：
 *当要覆盖前i个位置的时候，只要第i个没有被强制要求为opening bracket，那么这个位置可以为开和关括号，也就是 dp[i-1][j-1](当前为开括号)， dp[i-1][j+1] 当前为关括号.
 *
 */

#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 40;
int d;
int n, k;
bool arr[MAX_N];
int dp[MAX_N][MAX_N];

int main() {
	scanf("%d", &d);

	while(d--){
		scanf("%d %d", &n, &k);
		memset(arr, false, sizeof(arr));
		memset(dp, 0, sizeof(dp[0][0])*MAX_N*MAX_N);
		for(int i=0; i<k; i++){
			int tmp = -1;
			scanf("%d", &tmp);
			arr[tmp] = true;
		}
		dp[1][1] = 1;
		for(int i=0; i<=2*n; i++){
			if(i!=1){
				dp[1][i] = 0;
			}
		}
		for(int i=2; i<=2*n; i++){
			if(arr[i]){
				dp[i][0] = 0;
			}else{
				dp[i][0] = dp[i-1][1];
			}
			for(int j=1; j<=2*n; j++){
				if(arr[i]){
					dp[i][j] = dp[i-1][j-1];
				}else{
					dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
				}
			}
		}
		printf("%d\n", dp[2*n][0]);
	}

	return 0;
}

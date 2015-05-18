
/*
 * 题意：逗比游戏，A和B从一个两端开口的queue取数字，每一轮从一段开始去任意个数字（例如从左边开口取，就不能去右边）
 *
 * 思路：自己想出来的,用了记忆化搜索。每一个人的当前状态是从下一个人的一系列的最优取法中的最小值得出来的
 * 为什么一定是最小值？以为当前剩余的卡牌的总和是有限的。如果你的move把对手的最优解限制在了最小值，那么能拿到的
 * 牌的值一定是最大值。
 */

#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 110;
int n;
int arr[MAX_N];
int dp[2][MAX_N][MAX_N];

int memrize(int player, int left, int right);

int main() {
	while(true){
		scanf("%d", &n);
		if(n==0){break;}
		memset(arr, 0, sizeof(arr));
		for(int i=0; i<2; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					dp[i][j][k] = 1000000;
				}
			}
		}
		int sum = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		for(int i=0; i<n; i++){
			dp[0][i][i] = arr[i];
			dp[1][i][i] = arr[i];
		}
		memrize(0, 0, n-1);
		printf("%d\n", 2*dp[0][0][n-1]-sum);
	}
	return 0;
}

int memrize(int player, int left, int right){
	if(left==right){
		return dp[player][left][left];
	}else if(dp[player][left][right]!=1000000){
		return dp[player][left][right];
	}else{
		int tmp = 10000000;
		int current_sum = 0;
		for(int i=left; i<=right; i++){
			current_sum += arr[i];
		}
		for(int i=left+1; i<=right; i++){
			memrize((player+1)%2, i, right);
			if(tmp>dp[(player+1)%2][i][right]){
				tmp = dp[(player+1)%2][i][right];
			}
		}
		for(int i=right-1; i>=left; i--){
			memrize((player+1)%2, left, i);
			if(tmp>dp[(player+1)%2][left][i]){
				tmp = dp[(player+1)%2][left][i];
			}
		}
		if(tmp>0){
			dp[player][left][right] = current_sum;
		}else{
			dp[player][left][right] = current_sum-tmp;
		}
		return dp[player][left][right];
	}
}

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define L 200
using namespace std;

int T, l1, l2;
int dp[L][L];
char s1[L], s2[L];

int map[5][5]={
		{5,-1,-2,-1,-3},
		{-1,5,-3,-2,-4},
		{-2,-3,5,-2,-2},
		{-1,-2,-2,5,-1},
		{-3,-4,-2,-1,-100}
};

int table[128];

int main() {
	scanf("%d", &T);
	table[65] = 0;
	table[67] = 1;
	table[71] = 2;
	table[84] = 3;
	table[45] = 4;
	while(T--){
		scanf("%d %s %d %s", &l1, s1, &l2, s2);
		int row = l1+1;
		int col = l2+1;
		for(int i=0; i<L; i++){
			for(int j=0; j<L; j++){
				dp[i][j] = -500;
			}
		}
		dp[0][0] = 0;
		for(int i=1; i<row; i++){
			dp[i][0] = dp[i-1][0] + map[table[(int)s1[i-1]]][4];
		}
		for(int i=1; i<col; i++){
			dp[0][i] = dp[0][i-1] + map[4][table[(int)s2[i-1]]];
		}
		for(int i=1; i<row; i++){
			for(int j=1; j<col; j++){
				int tmp1 = dp[i-1][j] + map[table[(int)s1[i-1]]][4];
				int tmp2 = dp[i][j-1] + map[4][table[(int)s2[j-1]]];
				int tmp3 = dp[i-1][j-1] + map[table[(int)s1[i-1]]][table[(int)s2[j-1]]];
				dp[i][j] = max(tmp1,max(tmp2,tmp3));
			}
		}
		printf("%d\n", dp[row-1][col-1]);
	}
	return 0;
}

//#define USACO
#define FILEIN "numtri.in"
#define FILEOUT "numtri.out"
const int MAX = 1001;
int R;
int dp[MAX][MAX];
int map[MAX][MAX];

#include <iostream>
using namespace std;

void recursion(int row, int col);

int main() {
#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
#endif
	cin>>R;
	for(int i=1; i<=R; i++){
		for(int j=1; j<=i; j++){
			cin>>map[i][j];
			dp[i][j] = -1;
		}
	}
	recursion(1,1);
	cout<<dp[1][1]<<endl;
	return 0;
}

void recursion(int row, int col){
	if(dp[row][col]!=-1){
		return;
	}
	if(row==R){
		dp[row][col] = map[row][col];
		return;
	}
	recursion(row+1, col);
	recursion(row+1, col+1);
	dp[row][col] = max(dp[row+1][col], dp[row+1][col+1]) + map[row][col];
}

/*
 * 题意：寻找两个字符串的最长公共子序列， 但是这最长公共子序列必须是由某些连续的长度不小于k的子序列组成的
 *
 * 考点：对最长公共子序列的理解。
 * 参考了这个人的题解，自己想错了： http://spojsolutionsall.blogspot.ca/2015/01/spoj-dna-sequences.html
 *
 * 个人理解：
 *		最长公共子序列中这个2D数组的每个格子中的值增加1是当当前两个位置的char相等的时候。我们只有当相等
 *的数量大于或等于k的时候增加dp array的值。当segment的长度大于或等于k了，我们就一定要回去前面的格子。
 *学到LCS的核心部分就是当两个值更新的时候每个cell才会更新，抓住这一点。
 *
 */

#include <cstdio>
#include <string.h>
#include <stdlib.h>
#define N 1009
#include <algorithm>
using namespace std;

int main()
{
	char s[N], t[N];
	int lcs[N][N], cont[N][N];//lcs is answer matrix and cont is matrix for storing common segment length
	int k,z;
	scanf("%d", &k);
	while( k ){
		scanf("%s %s", s, t);
		int l1=strlen(s);
		int l2=strlen(t);
		cont[0][0] = 0;
		for(int i = 0; i < N; ++i) lcs[i][0] = lcs[0][i] = 0;
		for(int i = 1; i <= l1; ++i)
			for(int j = 1; j <= l2; ++j)
			{
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
				if(s[i-1]==t[j-1])
					cont[i][j]=cont[i-1][j-1]+1;
				else
					cont[i][j]=0;
				//update lcs matrix if segment size is greater than or equal to k
				if(cont[i][j] >= k)
					for(z= k; z <= cont[i][j]; z++)
						lcs[i][j] = max(lcs[i][j], lcs[i - z][j - z] + z);
			}
		printf("%d\n",lcs[l1][l2]);
		scanf("%d",&k);
	}
	return 0;
}

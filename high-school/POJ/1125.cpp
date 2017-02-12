#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 110;
const int MAX = 100000;
int n;
int num;
int tmp1;
int tmp2;
int d[MAX_N][MAX_N];

int main() {
	while(true){
		scanf("%d", &n);
		if(!n){break;}

		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				d[i][j] = MAX;
			}
		}
		for(int i=1; i<=n; i++){
			num = -1;
			scanf("%d", &num);
			for(int j=0; j<num; j++){
				scanf("%d %d", &tmp1, &tmp2);
				d[i][tmp1] = tmp2;
			}
		}
		for(int i=1; i<=n; i++){
			d[i][i] = 0;
		}

		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				for(int k=1; k<=n; k++){
					d[j][k] = min(d[j][k], d[j][i]+d[i][k]);
				}
			}
		}

		int ans = MAX;
		int ans2 = -1;
		int temp = 0;
		for(int i=1; i<=n; i++){
			temp = 0;
			for(int j=1; j<=n; j++){
				if(i==j){continue;}
				temp = max(temp, d[i][j]);
			}
			if(ans>temp){
				ans = temp;
				ans2 = i;
			}
		}

		printf("%d %d\n", ans2, ans);
	}
	return 0;
}

#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_N = 110;
int N;
int map[MAX_N][MAX_N];
int arr[MAX_N];

int main(){
	while(cin>>N){
		int tmp = -1;
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				cin>>tmp;
				map[i][j] = tmp + map[i-1][j];
			}
		}

		int ans = -1000000000;
		for(int i=1; i<=N; i++){
			for(int j=i; j<=N; j++){
				for(int k=1; k<=N; k++){
					arr[k] = map[j][k]-map[i-1][k];
				}

				int b = 0;
				int sum = -1000000000;
				for(int k=1; k<=N; k++){
					if(b>=0) b = b+arr[k];
					else b = arr[k];
					if(sum<b) sum = b;
				}

				ans = max(ans, sum);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

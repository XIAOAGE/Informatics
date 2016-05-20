#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>

using namespace std;

const int MAX_N = 524288;
int n, tmp;
string ans;
int global;
int dp[2][MAX_N];

bool solve(int a, int b);

int main() {

	int count = 1;
	while(true){
		cin>>n;
		if(!n){break;}
		int status = 0;
		ans = "";
		for(int i=0; i<n; i++){
			cin>>tmp;
			status = status + pow(2,(tmp-2));
		}
		global = status;
		for(int i=0; i<2; i++){
			for(int j=0; j<MAX_N; j++){
				dp[i][j] = -1;
			}
		}
		dp[0][0] = 0;
		dp[1][0] = 1;
		solve(0, status);
		cout<<"Test Case #"<<count++<<endl;
		if(!ans.length()){
			cout<<"There's no winning move."<<endl;
		}else{
			cout<<"The winning moves are: "<<ans<<endl;
		}
		cout<<endl;
	}

	return 0;
}

int change_number(int res, int number){
	res = res - pow(2,number);
	for(int i=number+1; i<19; i++){
		if((res>>i & 1) && i-number>1){
			if(!(res>>(i-number-2) & 1)){
				res -= pow(2,i);
			}else if(!((i+2)%(number+2))){
				res -= pow(2,i);
			}
		}
	}
	return res;
}

bool solve(int player, int status){
	if(dp[player][status]!=-1){
		return dp[player][status];
	}
	if(player==0){
		bool res = false;
		for(int i=0; i<19; i++){
			if(status>>i & 1){
				bool temp = solve(1, change_number(status,i));
				res = res || temp;
				if(temp && status==global){
					int n = i+2;
					string result;
					ostringstream convert;
					convert << n;
					result = convert.str();
					ans = ans + result +" ";
				}
			}
		}
		dp[player][status] = res;
		return res;
	}else{
		bool res = true;
		for(int i=0; i<19; i++){
			if(status>>i & 1){
				res = res && solve(0, change_number(status,i));
			}
		}
		dp[player][status] = res;
		return res;
	}
}

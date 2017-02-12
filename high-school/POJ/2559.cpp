#include <cstdio>
#include <stack>

using namespace std;

struct rect{
	long long h;
	long long w;
};

int n;
stack<rect> sta;
long long curw, curh;
long long ans;

int main() {
	while(true){
		scanf("%d", &n);
		if(n==0){break;}
		ans = -1;
		int totalw;
		for(int i=0; i<n; i++){
			scanf("%lld", &curh);
			curw = 1;
			if(sta.empty() || curh>=sta.top().h){
				rect tmp;
				tmp.h = curh;
				tmp.w = curw;
				sta.push(tmp);
			}else{
				totalw = 0;
				while(!sta.empty() && sta.top().h > curh){
					rect last = sta.top();
					sta.pop();
					totalw += last.w;
					if(totalw * last.h > ans){
						ans = totalw * last.h;
					}
				}
				rect push_new;
				push_new.w = totalw+curw;
				push_new.h = curh;
				sta.push(push_new);
			}
		}
		totalw = 0;
		while(!sta.empty()){
			rect re = sta.top();
			sta.pop();
			totalw += re.w;
			if(totalw*re.h>ans){
				ans = totalw*re.h;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

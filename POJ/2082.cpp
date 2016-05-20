#include <cstdio>
#include <stack>

using namespace std;

struct rect{
	int h;
	int w;
};

int n;
stack<rect> sta;
int curw, curh;
int ans;

int main() {
	while(true){
		scanf("%d", &n);
		if(n==-1){break;}
		ans = -1;
		int totalw;
		for(int i=0; i<n; i++){
			scanf("%d %d", &curw, &curh);
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
		printf("%d\n", ans);
	}
	return 0;
}

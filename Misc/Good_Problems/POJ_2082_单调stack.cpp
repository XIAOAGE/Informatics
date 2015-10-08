/*
 * 题意：有一系列的矩形（像柱状图一样），每一个矩形的高和宽都不等，求在这一系列矩形表达的范围中能形成的
 * 最大长方形的面积。
 *
 * 使用单调stack（找不到jian。。。）
 * 没input一个矩形就分析能否使stack中的stuff保证不递减
 * 注意当遇到一个小于stack顶部的一个矩形时保证，将stack中所有高度逼当前矩形高的全部弹出，进行合并操作
 * 合并完成后再压入stack中。
 *
 * 在弹出过程中，我们也是更新最大ans
 *
 * 完成输入后，我们把stack中所有的矩形都弹出进行如上操作，不同是我们当然不用再次合并然后压入stack中。
 *
 * 如果不明白可以看：http://blog.csdn.net/bobten2008/article/details/5116807
 */

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

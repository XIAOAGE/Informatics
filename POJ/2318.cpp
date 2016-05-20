#include <iostream>

using namespace std;

//holy fuck, never use parition as a name

const int MAX = 5100;
int n, m, x1, y1, x2, y2;

struct part{
	int leftUp;
	int leftLow;
	int rightUp;
	int rightLow;
};

part box[MAX];
int ans[MAX];
long cross_product(int a1, int a2, int a3, int b1, int b2, int b3);
bool check(part a, int b, int c);

int main() {

	while(true){
		part shot = {};
		for(int i=0; i<MAX; i++){
			box[i] = shot;
			ans[i] = 0;
		}
		cin>>n;
		if(!n) break;
		cin>>m>>x1>>y1>>x2>>y2;
		int last_x=x1, last_x2 = x1;
		int x, y;
		for(int i=0; i<n; i++){
			cin>>x>>y;
			part tmp = {last_x, last_x2, x, y};
			box[i] = tmp;
			last_x = x;
			last_x2 = y;
		}
		part tmp = {last_x, last_x2, x2, x2};
		box[n] = tmp;

		int X, Y;
		while(m--){
			cin>>X>>Y;
			for(int i=0; i<=n; i++){
				if(check(box[i], X, Y)){
					ans[i]++;
					break;
				}
			}
		}
		for(int i=0; i<=n; i++){
			cout<<i<<": "<<ans[i]<<endl;
		}
		cout<<endl;
	}
	return 0;
}

long cross_product(int a1, int a2, int a3, int b1, int b2, int b3){
	long long m1 = a2-a1;
	long long n1 = b2-b1;
	long long m2 = a3-a1;
	long long n2 = b3-b1;
	return m1*n2-m2*n1;
}

bool check(part shit, int X, int Y){
	long long tmp1 = cross_product(X, shit.leftUp, shit.leftLow, Y, y1, y2);
	long long tmp2 = cross_product(X, shit.rightUp, shit.rightLow, Y, y1, y2);
	return tmp1*tmp2<0;
}


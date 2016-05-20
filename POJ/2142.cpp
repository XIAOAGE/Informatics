#include <iostream>
#include <cmath>
using namespace std;
#define inf 0x3fffffff
#define LL __int64

LL gcd (LL a, LL b)
{
	return b ? gcd (b, a%b) : a;
}

LL Egcd (LL a, LL b, LL &x, LL &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	LL d = Egcd (b, a%b, x, y);
	LL tp = x;
	x = y;
	y = tp - a/b*y;
	return d;
}

int main()
{
	LL a, b, n, x, y, vx, vy, d;
	while (scanf ("%I64d%I64d%I64d", &a, &b, &n), (a||b||n))
	{
		d = gcd (a, b);
		a /= d;
		b /= d;
		n /= d;
		Egcd (a, b, x, y);
		/**********①令y是最小正整数解**********/
		vy = y*n;
		vy = (vy % a + a) % a;
		vx = (n-b*vy) / a;
		if (vx < 0)		//题目要的是使用砝码的个数，所以要正整数
			vx = -vx;
		/**********②令x是最小正整数解**********/
		x *= n;
		x = (x % b + b) % b;
		y = (n-a*x) / b;
		if (y < 0)		//同理
			y = -y;
		/**********③使得和最小**********/
		if (x + y < vx + vy)
			vx = x, vy = y;
		printf ("%I64d %I64d\n", vx, vy);
	}
	return 0;
}

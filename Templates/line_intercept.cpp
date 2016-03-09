#include <bits/stdc++.h>

using namespace std;

int cmp(int num)
{
    if(num==0) return 0;
    else if(num<0) return -1;
    else return 1;
}

int det(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return cmp((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
}

bool is_intercept(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    return det(x3, y3, x4, y4, x1, y1)*det(x3, y3, x4, y4, x2, y2)<=0 &&
    det(x1, y1, x2, y2, x3, y3)*det(x1, y1, x2, y2, x4, y4)<=0 && min(x1,x2)<=max(x3,x4) &&
    min(x3, x4)<=max(x1,x2) && min(y1,y2)<=max(y3,y4) && min(y3,y4)<=max(y1,y2);
}

int main()
{

}

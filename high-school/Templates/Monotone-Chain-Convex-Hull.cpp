/*
pseudo-code from http://www.algorithmist.com/
Input: a list P of points in the plane.

Sort the points of P by x-coordinate (in case of a tie, sort by y-coordinate).

Initialize U and L as empty lists.
The lists will hold the vertices of upper and lower hulls respectively.

for i = 1, 2, ..., n:
    while L contains at least two points and the sequence of last two points
            of L and the point P[i] does not make a counter-clockwise turn:
        remove the last point from L
    append P[i] to L

for i = n, n-1, ..., 1:
    while U contains at least two points and the sequence of last two points
            of U and the point P[i] does not make a counter-clockwise turn:
        remove the last point from U
    append P[i] to U

Remove the last point of each list (it's the same as the first point of the other list).
Concatenate L and U to obtain the convex hull of P.
Points in the result will be listed in counter-clockwise order.
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> point;

vector<point> vec;
int n;

bool cmp(point a, point b)
{
    if(a.first==b.first) return a.second<b.second;
    else return a.first<b.first;
}

int det(int x1, int y1, int x2, int y2)
{
    return x1*y2-x2*y1;
}

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main()
{
    scanf("%d", &n);
    //get the coordinates of the points
    for(int i=1; i<=n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        vec.push_back(point(i, tmp));
    }

    sort(vec.begin(), vec.end(), cmp);

    //upper chain
    vector<point> upper;
    upper.clear();
    for(int i=n-1; i>=0; i--)
    {
        int sz = upper.size();
        while(sz>=2 && det(upper[sz-1].first-upper[sz-2].first, upper[sz-1].second-upper[sz-2].second, vec[i].first-upper[sz-1].first, vec[i].second-upper[sz-1].second)<=0)
        {
           upper.pop_back();
           sz--;
        }
        upper.push_back(vec[i]);
    }

    //down chain...
    return 0;
}

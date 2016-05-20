#include <iostream>
#include <cmath>

using namespace std;

int t;
string line;
int dx[] = {0,-1,0,1,-1,0,1,-1,0,1};
int dy[] = {0,-1,-1,-1,0,0,0,1,1,1};

void solve()
{
    int cnt = 0;
    long long currentX = 0, currentY = 0, lastX = 0, lastY = 0;
    long long area = 0;
    while(line[cnt]!='5')
    {
        lastX = currentX, lastY = currentY;
        currentX += dx[line[cnt]-48], currentY += dy[line[cnt]-48];
        area += lastX*currentY - lastY*currentX;
        cnt++;
    }
    if(area<0) area = -1 * area;
    cout<<area/2;
    if(area%2)
    {
        cout<<".5";
    }
    cout<<endl;
}

int main()
{
    cin>>t;
    cin.ignore();
    while(t--)
    {
        getline(cin, line);
        solve();
    }
    return 0;
}

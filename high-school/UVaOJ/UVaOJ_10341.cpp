#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double p, q, r, s, t, u;

double cal(double x)
{
    double temp = p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*pow(x,2)+u;
    return temp;
}

int main()
{
    //freopen("/Users/dzuyokoxiao/Desktop/input.in", "r", stdin);
    while(cin>>p>>q>>r>>s>>t>>u)
    {
        double low = 0.0;
        double high = 1.0;
        double mid = 0;
        for(int i=0; i<100; i++)
        {
            mid = (low+high)/2.0;
            double tmp = cal(mid);
            if(tmp>0)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        if(abs(cal(mid)-0.0)<1e-8)
        {
            printf("%.4lf\n", mid);
        }
        else
        {
            cout<<"No solution"<<endl;
        }
    }
    return 0;
}
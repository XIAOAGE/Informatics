#include <cstdio>

using namespace std;

double a,c;
int b;

int main()
{
    int cnt = 1;
    while(scanf("%lf %d %lf", &a, &b, &c))
    {
        if(b==0) break;
        printf("Trip #%d: ", cnt++);
        double dist = a*b*3.1415927/12/5280;
        printf("%.2lf %.2lf", dist, dist/c*3600);
        printf("\n");
    }
    return 0;
}

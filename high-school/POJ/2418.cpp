#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, double> m;
string line;

int main()
{
    int sum = 0;
    map<string, double> :: iterator itr;
    while(getline(cin, line))
    {
        m[line]++;
        sum++;
    }
    
    for(itr=m.begin(); itr!=m.end(); itr++)
    {
        printf("%s %.4lf\n", itr->first.c_str(), itr->second*100/sum);
    }
    return 0;
}

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

string line;
int length;
ll numer, denom;

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}

void solve(int i, ll number, ll first)
{
    ll a, b;
    a = number-first;
    b = (pow(10, i)-1)*pow(10, length-i);
    if(a>b) return;
    ll tmp = gcd(a, b);
    a /= tmp;
    b /= tmp;
    if(b<denom)
    {
        numer = a;
        denom = b;
    }
}

int main()
{
    while(getline(cin, line))
    {
        if(line=="0") break;
        line = line.substr(2, line.length()-5);
        length = (int)line.length();
        ll number = atol(line.c_str());
        if(number==0)
        {
            cout<<"0/1"<<endl;
            continue;
        }
        numer = number / gcd(pow(10, length)-1, number);
        denom = (pow(10, length)-1) / gcd(pow(10, length)-1, number);
        bool judge = false;
        ll temp = number;
        int temp2 = length;
        while(!(number%10))
        {
            number/=10;
            length--;
            judge = true;
        }
        if(judge)
        {
            ll tmp = gcd(pow(10, length), number);
            if(pow(10, length)/tmp < denom)
            {
                numer = number/tmp;
                denom = pow(10, length)/tmp;
            }
        }
        number = temp;
        length = temp2;
        for(int i=1; i<length; i++)
        {
            int tmp = pow(10, i);
            ll first = number / tmp;
            solve(i, number, first);
        }
        cout<<numer<<"/"<<denom<<endl;
    }
    return 0;
}

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int t;
string line;

int main()
{
    cin>>t;
    cin.ignore();
    while(t--)
    {
        getline(cin, line);
        int left = 0, right = 0;
        int cnt = 0;
        int sign = 1;
        int leftSide = 1;
        while(cnt<line.length())
        {
            bool hasX = false;
            string term = "";
            int tmp = sign;
            int tmp2 = leftSide;
            while(cnt<line.length())
            {
                if(line[cnt]=='+')
                {
                    sign = 1;
                    break;
                }
                else if(line[cnt]=='-')
                {
                    sign = -1;
                    break;
                }
                else if(line[cnt]=='=')
                {
                    leftSide = -1;
                    sign = 1;
                    break;
                }
                if(line[cnt]!='x')
                {
                    term += line[cnt];
                }
                else    hasX  = true;
                cnt++;
            }
            istringstream ss(term);
            int fuckCpp;
            ss>>fuckCpp;
            if(hasX && term.length()==0) fuckCpp = 1;
            if(hasX) left += tmp * fuckCpp * tmp2;
            else right += tmp * fuckCpp * -1 *tmp2;
            cnt++;
        }
        if(left==0 && right!=0) cout<<"IMPOSSIBLE"<<endl;
        else if(left==0 && right==0) cout<<"IDENTITY"<<endl;
        else cout<<floor(right*1.0/(left*1.0))<<endl;
    }
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

string word;

string solve(int index)
{
    string suffix = word.substr(index, word.length());
    char tmp = suffix[0];
    char ans = ' ';
    for(int i=1; i<suffix.length(); i++)
    {
        if(suffix[i]>tmp && (ans==' ' || suffix[i]<ans))
        {
            ans = suffix[i];
        }
    }
    if(ans==' ') return "No Successor";
    string ret = "";
    ret += ans;
    bool used = false;
    sort(suffix.begin(), suffix.end());
    for(int i=0; i<suffix.length(); i++)
    {
        if(!used && suffix[i]==ans) used = true;
        else ret += suffix[i];
    }
    ret = word.substr(0, index)+ret;
    return ret;
}

int main()
{
    string ans;
    while(cin>>word, word!="#")
    {
        ans = "No Successor";
        for(int i=(int)word.length()-2; i>=0; i--)
        {
            ans = solve(i);
            if(ans!="No Successor") break;
        }
        cout<<ans<<endl;
    }
    return 0;
}

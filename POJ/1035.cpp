#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string vec[10010];
int cnt;

bool one(string word2, string word1)
{
    if(word1.length()-word2.length()!=1) return false;
    bool flag = true;
    for(int i=0, j=0; i<word2.length() && j<word1.length(); i++, j++)
    {
        if(word2[i]==word1[j]) continue;
        else if(flag)
        {
            flag = false;
            i--;
        }
        else return false;
    }
    return true;
}

bool two(string word2, string word1)
{
    if(word1.length()!=word2.length()) return false;
    bool flag = true;
    for(int i=0, j=0; i<word2.length() && j<word1.length(); i++, j++)
    {
        if(word2[i]==word1[j]) continue;
        else if(flag)
        {
            flag = false;
        }
        else return false;
    }
    return true;
}

int main()
{
    string line;
    cnt = 0;
    while(true)
    {
        cin>>line;
        if(line=="#") break;
        vec[cnt++] = line;
    }
    
    while(true)
    {
        cin>>line;
        if(line=="#") break;
        vector<string> vec2;
        bool flag = true;
        for(int i=0; i<cnt; i++)
        {
            if(vec[i]==line)
            {
                cout<<line<<" is correct"<<endl;
                flag = false;
                break;
            }
            else
            {
                if(one(vec[i], line) || two(vec[i], line) || one(line, vec[i]))
                {
                    vec2.push_back(vec[i]);
                }
            }
        }
        if(flag)
        {
            cout<<line<<": ";
            for(int i=0; i<vec2.size(); i++)
            {
                cout<<vec2[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

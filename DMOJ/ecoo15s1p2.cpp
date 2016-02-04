#include <bits/stdc++.h>

using namespace std;

int n;
string line;

int main()
{
    for(int z=0; z<10; z++)
    {
        cin>>n;
        cin.ignore();
        getline(cin, line);
        stack<string> sta;
        string word = "";
        for(int i=0; i<line.length(); i++)
        {
            if(line[i]==' ') continue;
            word = "";
            while(i<line.length() && line[i]!=' ' && word.length()<n) word += line[i++];
            i--;
            sta.push(word);
        }
        stack<string> s;
        while(!sta.empty())
        {
            s.push(sta.top());
            sta.pop();
        }
        int space = n;
        while(!s.empty())
        {
            space = n;
            while(!s.empty() && space>= s.top().length() && space>0)
            {
                cout<<s.top()<<" ";
                space = space - s.top().length()-1;
                s.pop();
            }
            cout<<endl;
        }
        cout<<"====="<<endl;
    }
    return 0;
}

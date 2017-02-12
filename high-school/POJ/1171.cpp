#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

short score[] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
short letter[26];
short arr[200];
short cnt[200];
bool mark[200];
string s;
char k[7];

void dfs(int index, int val)
{
    if(index==strlen(k))
    {
        mark[val] = true;
        cnt[val]++;
        return;
    }
    if(letter[k[index]-97]==0) return;
    letter[k[index]-97]--;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == k[index] && !(val>>i & 1))
        {
            dfs(index+1, val+(1<<i));
        }
    }
    letter[k[index]-97]++;
}

void init()
{
    int tmp;
    for(int i=0; i<1<<s.length(); i++)
    {
        tmp = 0;
        for(int j=0; j<s.length(); j++)
            if(i>>j & 1) tmp += score[s[j]-97];
        arr[i] = tmp;
    }
}

bool check(int a, int b)
{
    string w1, w2;
    for(int i=0; i<s.length(); i++)
    {
        if(a>>i & 1)
        {
            w1+=s[i];
        }
        if(b>>i & 1)
        {
            w2+=s[i];
        }
    }
    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());
    return !(w1==w2);
}

int main()
{
    cin>>s;
    for(int i=0; i<s.length(); i++)  ++letter[s[i]-97];
    init();
    while(scanf("%s", k)==1 && s[0]!='.')
    {
        dfs(0, 0);
        
    }
    int ans = -1;
    for(int i=1; i<1<<s.length(); i++)
    {
        if(!mark[i]) continue;
        ans = max(ans, (int)arr[i]);
        for(int j=i-1; j>=0; j--)
        {
            if(!mark[j] || (i&j)) continue;
            if(check(i, j) || cnt[i]>2) ans = max(ans, arr[i] + arr[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}

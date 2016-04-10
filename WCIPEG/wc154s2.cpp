#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> node;

int n;
set<node> st;

int cal(node a, node b)
{
    return abs(b.first-a.first)+abs(abs(b.second)-abs(a.second));
}

int main()
{
    scanf("%d", &n);
    int x, y;
    set<node>::iterator itr, prev, nxt;
    st.insert(node(1, 1));
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &x, &y);
        if(x%2==0) y = -y;
        node cur = node(x, y);
        itr = st.lower_bound(cur);
        if(itr==st.end()) ans += cal(*--itr, cur);
        else
        {
            nxt = itr;
            prev = --itr;
            ans += cal(*prev, cur)+cal(*nxt, cur)-cal(*prev, *nxt);
        }
        st.insert(cur);
        printf("%d\n", ans);
    }
    return 0;
}

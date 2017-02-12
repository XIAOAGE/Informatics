#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
 
pair<int, int> cow[2500 + 16];
pair<int, int> bottle[2500 + 16];
priority_queue<int, vector<int>, greater<int> > q;    // 优先级队列，小元素优先出队
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int C, L;
    cin >> C >> L;
    for (int i = 0; i < C; ++i)
    {
        cin >> cow[i].first >> cow[i].second;
    }
    for (int i = 0; i < L; ++i)
    {
        cin >> bottle[i].first >> bottle[i].second;
    }
    sort(cow, cow + C);
    sort(bottle, bottle + L);
    int cur = 0; // 现在正等待涂防晒霜的奶牛的index
    int result = 0;
    for (int i = 0; i < L; ++i)
    {
        while (cur < C && cow[cur].first <= bottle[i].first)
        {
            q.push(cow[cur].second);
            ++cur;
        }
 
        while (!q.empty() && bottle[i].second)
        {
            int maxSPF = q.top(); q.pop();
            // “奶牛上限”比这一瓶的上限大，说明这头奶牛可以被涂上防晒霜
            if (maxSPF >= bottle[i].first)
            {
                ++result;
                --bottle[i].second;
            }
            // else 这头奶牛不能被涂上，因为bottle是按SPF排过序的，没有比这瓶更小的SPF了
        }
    }
    cout << result << endl;
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif
    return 0;
}

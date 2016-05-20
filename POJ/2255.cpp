#include <iostream>

using namespace std;

string preorder, inorder;
int cnt;

void solve(int left, int right)
{
    if(left>right) return;
    if(left==right)
    {
        cout<<inorder[left];
        cnt++;
        return;
    }
    char root = preorder[cnt++];
    int index2 = -1;
    for(int i=left; i<=right; i++)
    {
        if(inorder[i]==root)
        {
            index2 = i;
            break;
        }
    }
    solve(left, index2-1);
    solve(index2+1, right);
    cout<<root;
}

int main()
{
    while(cin>>preorder>>inorder)
    {
        cnt = 0;
        solve(0, (int)preorder.length()-1);
        cin.ignore();
        cout<<endl;
    }
    return 0;
}

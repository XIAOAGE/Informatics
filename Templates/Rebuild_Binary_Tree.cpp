/*
 二叉树的重建，原题是来自USACO上的American Heritage。题意是给你一个二叉树的inorder遍历和preorder遍历，输出postorder遍历
 可以通过preorder的遍历，我们可以得到各个子树的根。
 通过各个子树的根我们就可以在inorder遍历上以根为中心分成左子树和右子树。
 这样就可以完成二叉树的重建。
 
 这道题有一个变种就是给定inorder遍历和postorder遍历，输出preorder遍历。
 实质上是一样的当我们吧postorder遍历当过来输出实际上是root->right->left。
 只是在recursion方面我们要先右子树再左子树。
 
 主要算法在solve()函数中。
 */

#include <iostream>
#include <cstring>
#define USACO
#define FILEIN "heritage.in"
#define FILEOUT "heritage.out"

struct node
{
    char letter;
    node *left_kid;
    node *right_kid;
};

using namespace std;
string inorder;
string preorder;
node *root;

void input();
//low->当前子树在inorder这个string里的左边边界； up->右边边界； n->n是preorder的index，可以从preorder中得到我们当前子树的根
void solve(node *current, int low, int up, int n)
{
    int index = -1;
    for(int i=low; i<=up; i++)
    {
        if(inorder[i]==preorder[n]) index = i;
    }
    current->letter = preorder[n];
    if(index-1>=low)
    {
        current->left_kid = new node();
        solve(current->left_kid, low, index-1, n+1);
    }
    if(index+1<=up)
    {
        current->right_kid = new node();
        solve(current->right_kid, index+1, up, n+index-low+1); //n+index-low+1->其实是为了跳过几个在左子树用过了的node，因为左子树先。
    }
}

void post_order(node *current)
{
    if(current==NULL) return;
    post_order(current->left_kid);
    post_order(current->right_kid);
    cout<<current->letter;
}

int main()
{
#ifdef USACO
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
#endif
    input();
    root = new node;
    solve(root,0,(int)inorder.length()-1,0);
    post_order(root);
    cout<<endl;
    return 0;
}

void input()
{
    cin>>inorder>>preorder;
}
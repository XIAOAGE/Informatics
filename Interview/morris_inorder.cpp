#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *left, *right;
    node(int val): val{val}, left{nullptr}, right{nullptr}{}
};

void morrisTraversal(node* root) {
    node *current=root, *pre=nullptr;
    while(current!=nullptr) {
        if(current->left==nullptr) {
            cout<<current->val<<endl;
            current = current->right;
        } else {
            pre = current->left;
            while(pre->right!=nullptr && pre->right!=current) pre = pre->right;
            if(pre->right==nullptr) {
                pre->right = current;
                current = current->left;
            } else {
                cout<<current->val<<endl;
                pre->right = nullptr;
                current = current->right;
            }
        }
    }
}

int main()
{
    node* root = new node(4);
    root->left = new node(2);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right = new node(5);
    morrisTraversal(root);
    return 0;
}

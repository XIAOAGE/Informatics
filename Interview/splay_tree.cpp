#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node(int val): val{val}, left{nullptr}, right{nullptr} {}
};

node* rightRotate(node* root) {
    node* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    return tmp;
}

node* leftRotate(node* root) {
    node* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}

node* splay(node* root, int k) {
    if(root==nullptr || root->val==k) {
        return root;
    } else if(root->val > k) {
        if(root->left && root->left->val>k) {
            root->left->left = splay(root->left->left, k);
            root = rightRotate(root);
        } else if(root->left && root->left->val<k) {
            root->left->right = splay(root->left->right, k);
            if(root->left->right)
                root->left = leftRotate(root->left);
        }
        if(root->left) return rightRotate(root);
        else return root;
    } else {
        if(root->right && root->right->val>k) {
            root->right->left = splay(root->right->left, k);
            if(root->right->left)
                root->right = rightRotate(root->right);
        } else if(root->right && root->right->val<k) {
            root->right->right = splay(root->right->right, k);
            root = leftRotate(root);
        }
        if(root->right) return leftRotate(root);
        else return root;
    }
}

node* insert(node* root, int k) {
    if(!root) return new node(k);
    node* sroot = splay(root, k);

    if(sroot->val > k) {
        node* tmp = new node(k);
        tmp->left = sroot->left;
        tmp->right = sroot;
        sroot->left = nullptr;
        sroot = tmp;
    } else if(sroot->val < k) {
        node* tmp = new node(k);
        tmp->right = sroot->right;
        tmp->left = sroot;
        sroot->right = nullptr;
        sroot = tmp;
    }

    return sroot;
}

node* remove(node* root, int k) {
    if(!root) return root;
    node* sroot = splay(root, k);

    if(sroot->val != k) {
        return sroot;
    } else {
        node* garbage = nullptr;
        if(!sroot->left) {
            garbage = sroot;
            sroot = sroot->right;
        } else {
            sroot->left = splay(sroot->left, k);
            sroot->left->right = sroot->right;
            garbage = sroot;
            sroot = sroot->left;
        }
        delete garbage;
    }
    return sroot;
}

node* search(node* root, int k) {
    return splay(root, k);
}

// void in_order(node* root, vector<int>& vec) {
//     if(!root) return;
//     in_order(root->left, vec);
//     vec.push_back(root->val);
//     in_order(root->right, vec);
// }

// bool test_bst() {
//     random_device rd;
//     mt19937 rng(rd());
//     uniform_int_distribution<int> uni(0, 100000);
//     unordered_set<int> unst;
//     for(int i=0; i<100; i++) {
//         unst.insert(uni(rng));
//     }
//     //cout<<"Test set size: "<<unst.size()<<endl;
//     set<int> st;
//     node* splay_tree = nullptr;
//     for(auto x: unst) {
//         st.insert(x);
//         splay_tree = insert(splay_tree, x);
//     }
    
//     for(auto x: unst) {
//         st.erase(x);
//         splay_tree = remove(splay_tree, x);
        
//         vector<int> vec;
//         in_order(splay_tree, vec);
    
//         int i = 0;
//         for(auto x: st) {
//             if(x!=vec[i++]) return false;
//         }
//     }
//     return true;
// }

// int main() {
//     for(int i=0; i<20; i++) {
//         cout<<test_bst()<<endl;
//     }
// }
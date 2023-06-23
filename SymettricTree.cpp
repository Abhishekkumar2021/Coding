#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* a, TreeNode* b){
    if(a==NULL && b==NULL) return true;
    if(a==NULL || b==NULL) return false;

    if(a->val != b->val) return false;

    return isSymmetric(a->left, b->right) && isSymmetric(a->right, b->left); 
}

bool isSymmetric(TreeNode* root){
    if(root==NULL) return true;
    return isSymmetric(root->left, root->right);
}

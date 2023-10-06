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

vector<TreeNode*> generate(int l, int r){
    if(l==r) return {new TreeNode(l)};

    vector<TreeNode*> ans;
    for(int i=l; i<=r; i++){
        // Take i as the root Node
        vector<TreeNode*> left = generate(l, i-1);
        vector<TreeNode*> right = generate(i+1, r);
        for(auto &leftSub: left){
            for(auto &rightSub: right){
                TreeNode* root = new TreeNode(i);
                root->left = leftSub;
                root->right = rightSub;
                ans.push_back(root);
            }
        }
    }
    return ans;
}
vector<TreeNode*> generateTrees(int n){
    return generate(1, n);
}
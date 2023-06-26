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

class Solution {
public:
    TreeNode* build(vector<int> &pre, vector<int> &in, int &rootIdx, int start, int end){
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(pre[rootIdx]);
        int idx = start;
        while(in[idx]!=pre[rootIdx]) idx++;
        rootIdx++;
        root->left = build(pre,in,rootIdx,start,idx-1);
        root->right = build(pre,in,rootIdx,idx+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder,inorder,rootIdx,0,preorder.size()-1);
    }
};
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
    TreeNode* build(vector<int> &post, vector<int> &in, int &rootIdx, int start, int end){
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(post[rootIdx]);
        int idx = start;
        while(in[idx]!=post[rootIdx]) idx++;
        rootIdx--;
        root->right = build(post,in,rootIdx,idx+1,end);
        root->left = build(post,in,rootIdx,start,idx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIdx = postorder.size()-1;
        return build(postorder,inorder,rootIdx,0,postorder.size()-1);
    }
};
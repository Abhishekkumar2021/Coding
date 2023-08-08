#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> cousins(TreeNode* A, int B) {
    unordered_map<int , int> parent;
    unordered_map<int , int> level;
    queue<TreeNode*> q;
    q.push(A);
    parent[A->val] = NULL;
    level[A->val] = 0;

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
            parent[temp->left->val] = temp->val;
            level[temp->left->val] = level[temp->val] + 1;
        }
        if(temp->right){
            q.push(temp->right);
            parent[temp->right->val] = temp->val;
            level[temp->right->val] = level[temp->val] + 1;
        }
    }

    // Check if cousins exist: sibilings are not cousins
    if(parent[B] == NULL || level[B] == 1) return {};

    // Find cousins
    vector<int> ans;
    for(auto it: level){
        if(it.second == level[B] && parent[it.first] != parent[B]){
            ans.push_back(it.first);
        }
    }
    return ans;
}